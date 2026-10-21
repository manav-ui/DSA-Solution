
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> nums(n);
    bool divisible = false;

    for (auto &it : nums) {
        ll x;
        cin >> x;
        it = x % m;
        if (it == 0) {
            divisible = true;
        }
    }

    if (divisible || n >= m) {
        cout << "YES\n";
        return;
    }

    vector<bool> dp(m, false);

    for (auto it : nums) {
        vector<bool> ndp = dp;

        ndp[it] = true;

        for (int i = 0; i < m; i++) {
            if (dp[i]) {
                int rem = (i + it) % m;
                ndp[rem] = true;
            }
        }

        dp = ndp;

        if (dp[0]) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
