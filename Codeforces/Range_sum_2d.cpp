// https://codeforces.com/group/c3FDl9EUi9/contest/262795/problem/G
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<long long>> pre(n + 1, vector<long long>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            long long a;
            cin >> a;

            pre[i][j] = a
                      + pre[i - 1][j]
                      + pre[i][j - 1]
                      - pre[i - 1][j - 1];
        }
    }
    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long long ans =
              pre[x2][y2]
            - pre[x1 - 1][y2]
            - pre[x2][y1 - 1]
            + pre[x1 - 1][y1 - 1];

        cout << ans << '\n';
    }

    return 0;
}