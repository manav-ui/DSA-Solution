
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;

vector<ll> fac, inv;

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void factorial(int n) {
    fac.resize(n + 1);
    inv.resize(n + 1);

    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % MOD;

    inv[n] = power(fac[n], MOD - 2);

    for (int i = n; i >= 1; i--)
        inv[i - 1] = inv[i] * i % MOD;
}

ll nCr(int n, int r) {
    if (r < 0 || r > n)
        return 0;

    return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int &x : a)
            cin >> x;

        sort(a.begin(), a.end(), greater<int>());

        int cutoff = a[k - 1];

        int total = 0;
        int selected = 0;

        for (int x : a) {
            if (x == cutoff)
                total++;
        }

        for (int i = 0; i < k; i++) {
            if (a[i] == cutoff)
                selected++;
        }

        factorial(n);

        cout << nCr(total, selected) << '\n';
    }

    return 0;
}
