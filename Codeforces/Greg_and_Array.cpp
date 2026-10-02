//https://codeforces.com/contest/296/problem/C
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> l(m + 1), r(m + 1);
    vector<ll> d(m + 1);

    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i] >> d[i];
    }

    vector<ll> cnt(m + 2, 0);

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        cnt[x]++;
        cnt[y + 1]--;
    }

    for (int i = 1; i <= m; i++) {
        cnt[i] += cnt[i - 1];
    }
    vector<ll> diff(n + 2, 0);

    for (int i = 1; i <= m; i++) {
        ll times = cnt[i];

        diff[l[i]] += d[i] * times;
        diff[r[i] + 1] -= d[i] * times;
    }

    ll add = 0;

    for (int i = 1; i <= n; i++) {
        add += diff[i];
        a[i] += add;

        cout << a[i] << " ";
    }

    cout << '\n';

    return 0;
}