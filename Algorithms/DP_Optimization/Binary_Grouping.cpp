//Binary Grouping (Binary Splitting) + Bitset DP.
#include <bits/stdc++.h>
using namespace std;

const int MAXK = 1000005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n), m(n);
    int total = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> m[i];
        total += a[i] * m[i];
    }

    if (k > total) {
        cout << "NO\n";
        return 0;
    }

    // Use the smaller complementary target
    k = min(k, total - k);

    bitset<MAXK> dp;
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int x = 0; (1 << x) <= m[i]; x++) {
            int take = (1 << x);

            dp |= (dp << (a[i] * take));

            m[i] -= take;
        }

        // Process the remaining copies
        dp |= (dp << (a[i] * m[i]));
    }

    cout << (dp[k] ? "YES\n" : "NO\n");

    return 0;
}