#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        long long ans = 0;

        unordered_map<int, array<vector<int>, 2>> pos;

        for (int i = 0; i + 4 < n; i++) {
            int sum = a[i] + a[i + 2] - a[i + 4];

            auto &p = pos[sum][i % 2];

            ans += upper_bound(p.begin(), p.end(), i - 6) - p.begin();
            ans += pos[sum][1 - (i % 2)].size();

            p.push_back(i);
        }

        cout << ans << '\n';
    }

    return 0;
}