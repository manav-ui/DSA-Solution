
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++) {
        dp[i][i] = nums[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int f = 0; f + len <= n; f++) {
            int b = f + len - 1;

            ll takeFirst = nums[f] - dp[f + 1][b];
            ll takeLast = nums[b] - dp[f][b - 1];

            dp[f][b] = max(takeFirst, takeLast);
        }
    }

    ll total = 0;
    for (ll v : nums) {
        total += v;
    }

    ll diff = dp[0][n - 1];

    cout << (total + diff) / 2 << '\n';

    return 0;
}
