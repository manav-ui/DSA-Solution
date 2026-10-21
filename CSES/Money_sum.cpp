
#include <bits/stdc++.h>
using namespace std;

const int MAXS = 100000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    bitset<MAXS + 1> dp;
    dp[0] = 1;

    int total = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        dp |= (dp << x);
        total += x;
    }

    vector<int> ans;

    for (int s = 1; s <= total; s++) {
        if (dp[s]) {
            ans.push_back(s);
        }
    }

    cout << ans.size() << '\n';

    for (int s : ans) {
        cout << s << ' ';
    }

    cout << '\n';

    return 0;
}
