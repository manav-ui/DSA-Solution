
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> nums(n);
    vector<int> dp(x + 1, INT_MAX);

    dp[0] = 0;

    for (auto &it : nums) {
        cin >> it;
    }

    for (auto it : nums) {
        for (int i = it; i <= x; i++) {
            if (dp[i - it] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - it]);
            }
        }
    }

    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
