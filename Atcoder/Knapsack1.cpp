
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    cin >> n >> W;

    vector<ll> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        int wt, val;
        cin >> wt >> val;

        for (int w = W; w >= wt; w--) {
            dp[w] = max(dp[w], dp[w - wt] + val);
        }
    }

    cout << dp[W] << '\n';

    return 0;
}
