
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> pref(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        pref[i] = (pref[i - 1] + x % k) % k;
    }

    vector<ll> freq(k, 0);
    ll ans = 0;

    for (int r = k + 1; r <= n; r++) {
        freq[pref[r - k - 1]]++;
        ans += freq[pref[r]];
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
