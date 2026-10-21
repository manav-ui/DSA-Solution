#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;
void solve(){
    int t;
    cin >> t;
    while(t--){
        int a , b;
        cin >> a >> b;
        if(a <= b){
            cout << -1 << endl;
        }else{
            cout << min(b, a-b) << endl;
        }
    }
}
int main(){
    solve();
    return 0;
}