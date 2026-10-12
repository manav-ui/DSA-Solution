//https://cses.fi/problemset/task/1072

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    for (long long i = 1; i <= n; i++) {
        long long sq = i * i;

        long long total = sq * (sq - 1) / 2;
        long long attack = 4 * (i - 1) * (i - 2);

        long long ans = total - attack;

        cout << ans << '\n';
    }

    return 0;
}
