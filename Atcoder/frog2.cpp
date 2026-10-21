
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    vector<int> dp(n + 1, INT_MAX);
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        for (int j = max(1, i - k); j < i; j++) {
            dp[i] = min(dp[i],
                        dp[j] + abs(h[i] - h[j]));
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
