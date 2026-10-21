// Problem: B. Perfect Number
// Contest: Codeforces - Codeforces Round rgb(0, 102, 73) (Div. 2)
// URL: https://codeforces.com/contest/919/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
 * Author: bubu2006
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> v;
int n;
ll mem[20][11];

ll dp(int pos, int sum, bool lo) {
    if(sum > 10) return 0;
    if(pos == n) return (sum == 10);
    
    ll& res = mem[pos][sum];
    if(lo && res != -1) return res;
    
    ll ans = 0;
    int mx = lo ? 9 : v[pos];
    for(int d = 0; d <= mx; d++)
        ans += dp(pos + 1, sum + d, lo || (d < mx));
    
    return lo ? res = ans : ans;
}

ll solve(ll x) {
    v.clear();
    while(x) {
        v.push_back(x % 10);
        x /= 10;
    }
    reverse(v.begin(), v.end());
    n = v.size();
    
    memset(mem, -1, sizeof mem);
    return dp(0, 0, 0);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    ll k;
    cin >> k;
    
    ll l = 1;
    ll r = 1e18;
    
    while(l < r - 1) {
        ll m = (l + r) / 2;
        if(solve(m) >= k) r = m;
        else l = m;
    }
    
    cout << r << '\n';
}