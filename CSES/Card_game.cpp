
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1000000007;

vector<ll> arr;
vector<ll> fac(10001);
vector<ll> inv(10001);

ll exponential(ll base, ll power) {
    ll res = 1;

    while (power) {
        if (power & 1) {
            res = res * base % mod;
        }

        base = base * base % mod;
        power >>= 1;
    }

    return res;
}

void factorial() {
    fac[0] = 1;

    for (int i = 1; i <= 10000; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
}

void inverse() {
    inv[10000] = exponential(fac[10000], mod - 2);

    for (int i = 10000; i >= 1; i--) {
        inv[i - 1] = inv[i] * i % mod;
    }
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;

    return fac[n] * inv[r] % mod
         * inv[n - r] % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    factorial();
    inverse();

    for (int tc = 1; tc <= t; tc++) {
        int N, K;
        cin >> N >> K;

        arr.resize(N);

        for (auto &x : arr) {
            cin >> x;
        }

        sort(arr.begin(), arr.end());

        ll ans = 0;

        for (int i = K - 1; i < N; i++) {
            ll ways = nCr(i, K - 1);

            ll contribution = (arr[i] % mod) * ways % mod;

            ans = (ans + contribution) % mod;
        }

        cout << "Case #" << tc << ": " << ans << '\n';
    }

    return 0;
}
