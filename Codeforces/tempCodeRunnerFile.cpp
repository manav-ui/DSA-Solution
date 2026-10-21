#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
void solve(){
    ll n,m;
    cin >> n >> m;
    vector<ll> nums(n);
    for(auto &it : nums){
        ll x ;
        cin >> x;
        it = x % m;
    }
    vector<bool> dp(m,false);
    for(auto it : nums){
        for(int i = m - 1; i >=0; i++){
            if(it == i) dp[i] = true;
            else if(dp[i]){
                int x = (i + it) % m;
                dp[x] = true;
            }
        }
    }
    cout<< (dp[0] ? "YES" : "NO") << endl;
}
int main(){
    solve(); 
    return 0;
}