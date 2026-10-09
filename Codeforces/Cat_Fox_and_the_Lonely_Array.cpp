#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    int totalOR = 0;

    for (int &x : a) {
        cin >> x;
        totalOR |= x;
    }

    int ans = n;

    // last[b] = last position where bit b occurred
    vector<int> last(20, -1);

    for (int i = 0; i < n; i++) {

        // Update last occurrence of every set bit
        for (int b = 0; b < 20; b++) {
            if (a[i] & (1 << b)) {
                last[b] = i;
            }
        }

        // Find the furthest required bit
        int farthest = i;

        for (int b = 0; b < 20; b++) {
            if (totalOR & (1 << b)) {
                if (last[b] == -1) {
                    farthest = n;
                    break;
                }

                farthest = max(farthest, last[b]);
            }
        }

        if (farthest < n) {
            ans = min(ans, farthest - i + 1);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}