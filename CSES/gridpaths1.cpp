
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;

            if (c == '*') {
                dp[j] = 0;
            } else if (j > 0) {
                dp[j] = (dp[j] + dp[j - 1]) % mod;
            }
        }
    }

    cout << dp[n - 1] << '\n';

    return 0;
}
