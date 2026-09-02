#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(ll x, ll w, ll h, ll n) {
    return (x / w) >= (n + (x / h) - 1) / (x / h);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll w, h, n;
    cin >> w >> h >> n;

    ll low = 1, high = 1e18;
    ll ans = -1;

    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (check(mid, w, h, n)) {
            ans = mid;      
            high = mid - 1;  
        } 
        else {
            low = mid + 1; 
        }
    }

    cout << ans << '\n';
}