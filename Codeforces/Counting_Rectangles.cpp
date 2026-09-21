//https://codeforces.com/contest/1722/problem/E
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        long long grid[1001][1001] = {};

        for (int i = 0; i < n; i++) {
            int h, w;
            cin >> h >> w;
            grid[h][w] += 1LL * h * w;
        }

        long long pref[1001][1001] = {};

        for (int h = 1; h <= 1000; h++) {
            for (int w = 1; w <= 1000; w++) {
                pref[h][w] = grid[h][w]
                           + pref[h - 1][w]
                           + pref[h][w - 1]
                           - pref[h - 1][w - 1];
            }
        }

        while (q--) {
            int hs, ws, hb, wb;
            cin >> hs >> ws >> hb >> wb;

            long long ans = pref[hb - 1][wb - 1]
                          - pref[hs][wb - 1]
                          - pref[hb - 1][ws]
                          + pref[hs][ws];

            cout << ans << '\n';
        }
    }

    return 0;
}