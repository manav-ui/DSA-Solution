
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n + 1), freq(n + 1), vis(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    // Step 1: Find cycle lengths
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;

        int u = i, len = 0;

        while (!vis[u]) {
            vis[u] = 1;
            u = p[u];
            len++;
        }

        freq[len]++;
    }

    // Step 2: Calculate maximum-answer helper
    int curr = 0;

    for (int len = 2; len <= n; len++) {
        curr += freq[len] * (len / 2);
    }

    int mx = min({n, 2 * k, k + curr});

    // Step 3: Subset-sum DP using binary grouping
    bitset<1000001> dp;
    dp[0] = 1;

    for (int len = 1; len <= n; len++) {
        int cnt = freq[len];

        for (int take = 1; cnt > 0; take *= 2) {
            int quantity = min(take, cnt);
            int weight = quantity * len;

            dp |= (dp << weight);

            cnt -= quantity;
        }
    }

    // Step 4: Calculate minimum
    int mn = dp[k] ? k : min(k + 1, n);

    cout << mn << ' ' << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
