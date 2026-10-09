#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

ll power(ll a, ll b) {
    ll ans = 1;

    while (b > 0) {
        if (b & 1)
            ans = ans * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return ans;
}

void solve() {
    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        cout << power(n, k) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}