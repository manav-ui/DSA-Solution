#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n & 1) {
            cout << 1 << " " << n - 1 << '\n';
            continue;
        }

        if ((n & (n - 1)) == 0) {
            cout << -1 << '\n';
            continue;
        }

        int A = n & (-n);

        int B = n ^ A;

        cout << A << " " << B << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}