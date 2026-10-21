//https://codeforces.com/blog/entry/97396
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    int S = 0;

    for (int &x : A) {
        cin >> x;
        S += x;
    }

    // Frequency compression
    map<int, int> freq;
    for (int x : A) {
        if (x > 0) freq[x]++;
    }

    vector<int> dp(S + 1, 0);
    dp[0] = 1;

    for (auto [w, k] : freq) {
        vector<int> old = dp;
        fill(dp.begin(), dp.end(), 0);

        for (int r = 0; r < w && r <= S; r++) {
            int cnt = 0;

            for (int s = r; s <= S; s += w) {
                cnt += old[s];

                int remove = s - (k + 1) * w;
                if (remove >= 0) {
                    cnt -= old[remove];
                }

                dp[s] = (cnt > 0);
            }
        }
    }

    for (int s = 0; s <= S; s++) {
        if (dp[s]) cout << s << ' ';
    }
    cout << '\n';

    return 0;
}