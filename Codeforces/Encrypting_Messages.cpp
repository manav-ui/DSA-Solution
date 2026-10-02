//https://codeforces.com/contest/177/problem/D2
#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
using ll = long long;
using vll = vector<ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, c; cin >> n >> m >> c;

    vll a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vll diff(n + m, 0);

    for (int j = 0; j < m; j++) {
        diff[j] += b[j];
        diff[n - m + 1 + j] -= b[j];
    }

   
    for (int i = 1; i < n; i++) diff[i] += diff[i - 1];

    for (int i = 0; i < n; i++) {
        cout << (a[i] + diff[i]) % c << " ";
    }
    cout << nl;
    return 0;
}