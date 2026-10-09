#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;
int MAXN ;
vector<ll> fac, inv;

ll exp(ll base, ll power, ll mod) {
    ll res = 1;
    base %= mod;

    while (power > 0) {
        if (power & 1)
            res = res * base % mod;

        base = base * base % mod;
        power >>= 1;
    }

    return res;
}

void factorial() {
    fac.resize(MAXN + 1);
    fac[0] = 1;

    for (int i = 1; i <= MAXN; i++)
        fac[i] = fac[i - 1] * i % MOD;
}

void inverse() {
    inv.resize(MAXN + 1);

    inv[MAXN] = exp(fac[MAXN], MOD - 2, MOD);

    for (int i = MAXN; i >= 1; i--)
        inv[i - 1] = inv[i] * i % MOD;
}

ll choose(int n, int r) {
    if (r < 0 || r > n)
        return 0;

    return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;
    vector<int> map(26,0);

    for(auto it : str){
        map[it - 'a']++;
    }
    MAXN = str.size();
    factorial();
    inverse();
    long long ans = fac[MAXN] ;
    for(auto it : map){
        ans = ans * inv[it] % MOD;
    }
    cout << ans;
    return 0;
}