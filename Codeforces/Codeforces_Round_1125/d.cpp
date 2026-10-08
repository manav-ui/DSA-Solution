#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Lab {
    ll a, b, c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll k;
        cin >> n >> k;

        vector<Lab> v(n);
        ll low = LLONG_MAX;

        for (auto &[a, b, c] : v) {
            cin >> a >> b >> c;
            low = min(low, a + b + c);
        }

        auto check = [&](ll x) {
            ll need = 0;

            for (auto [a, b, c] : v) {
                ll sum = a + b + c;

                if (sum >= x)
                    continue;

                ll d = x - sum;

                if (a == b && b == c)
                    return false;

                if (a <= b && b <= c) {
                    ll cost = 2 * min(b - a + 1, c - b + 1);
                    need += d + cost;
                } else {
                    need += d;
                }

                if (need > k)
                    return false;
            }

            return true;
        };

        ll high = low + k;

        while (low <= high) {
            ll mid = low + (high - low) / 2;

            if (check(mid))
                low = mid + 1;
            else
                high = mid - 1;
        }

        cout << high << '\n';
    }

    return 0;
}