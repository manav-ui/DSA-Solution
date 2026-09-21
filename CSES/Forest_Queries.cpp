// https://cses.fi/problemset/task/1652
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> pre(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;

            int val = (c == '*');

            pre[i][j] = val
                      + pre[i - 1][j]
                      + pre[i][j - 1]
                      - pre[i - 1][j - 1];
        }
    }

    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        int ans = pre[y2][x2]
                - pre[y1 - 1][x2]
                - pre[y2][x1 - 1]
                + pre[y1 - 1][x1 - 1];

        cout << ans << '\n';
    }
}