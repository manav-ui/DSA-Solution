
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ll total = 1LL * n * (n + 1) / 2;

    if (total % 2 != 0) {
        cout << 0 << '\n';
        return 0;
    }

    int target = total / 2;

    vector<ll> dp(target + 1, 0);
    dp[0] = 1;

    for (int x = 1; x <= n; x++) {
        for (int s = target; s >= x; s--) {
            dp[s] = (dp[s] + dp[s - x]) % MOD;
        }
    }
    cout << dp[target] * 500000004 % MOD << '\n';

    return 0;
}
