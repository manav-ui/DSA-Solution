#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n ;
    cin >> n;
    while(n--){
        int l , r;
        cin >> l >> r;
        int op = l & r;
        cout << (l ^ op) + (r ^op) << endl;
    }
}
int main(){
    solve();
    return 0;
}