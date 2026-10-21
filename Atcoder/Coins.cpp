
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<double> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));

    dp[0][0] = 1.0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] += dp[i - 1][j] * (1.0 - p[i - 1]);

            if (j > 0) {
                dp[i][j] += dp[i - 1][j - 1] * p[i - 1];
            }
        }
    }

    double ans = 0.0;

    for (int j = n / 2 + 1; j <= n; j++) {
        ans += dp[n][j];
    }

    cout << fixed << setprecision(10) << ans << '\n';

    return 0;
}
