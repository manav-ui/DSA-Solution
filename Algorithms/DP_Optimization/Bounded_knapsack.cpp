//bounded knapsack optimization using frequency grouping
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W;
    cin >> N >> W;

    vector<int> a(N);
    map<int, int> freq;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    // dp[w] = minimum number of copies of the
    // current cost used to make sum w.
    // -1 means sum w is impossible.
    vector<int> dp(W + 1, -1);
    dp[0] = 0;

    for (auto [cost, count] : freq) {
        for (int w = 0; w <= W; w++) {
            if (dp[w] >= 0) {
                dp[w] = 0;
            }
            else if (w >= cost &&
                     dp[w - cost] >= 0 &&
                     dp[w - cost] < count) {
                dp[w] = dp[w - cost] + 1;
            }
            else {
                dp[w] = -1;
            }
        }
    }

    for (int w = 0; w <= W; w++) {
        cout << (dp[w] >= 0 ? "YES" : "NO");
        if (w < W) cout << ' ';
    }
    cout << '\n';

    return 0;
}