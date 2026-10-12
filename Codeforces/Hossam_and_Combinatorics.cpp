//https://codeforces.com/problemset/problem/1771/A

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int mini = INT_MAX;
        int min_count = 0;
        int maxi = INT_MIN;
        int max_count = 0;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;

            if (a < mini) {
                mini = a;
                min_count = 1;
            } else if (a == mini) {
                min_count++;
            }

            if (a > maxi) {
                maxi = a;
                max_count = 1;
            } else if (a == maxi) {
                max_count++;
            }
        }

        if (mini == maxi) {
            cout << 1LL * n * (n - 1) << '\n';
        } else {
            cout << 2LL * min_count * max_count << '\n';
        }
    }

    return 0;
}
