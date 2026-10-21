
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;

    int n1 = s.size() + 1;
    int n2 = t.size() + 1;

    vector<vector<int>> dp(n1, vector<int>(n2, 0));

    for (int i = 1; i < n1; i++) {
        for (int j = 1; j < n2; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string ans = "";
    int i = n1 - 1;
    int j = n2 - 1;

    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            ans.push_back(s[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << '\n';
}

int main() {
    solve();
    return 0;
}
