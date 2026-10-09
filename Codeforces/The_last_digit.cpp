#include<bits/stdc++.h>
using namespace std;
void power(int a, int b){
    int res = 1;
    while(b){
        if(b & 1){
            res *= a;
            res %= 10;
        }
        a= (a*a) % 10;
        b >>= 1;
    }
    return;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        a %= 10;
        if(a == 0) cout << a;
        else{
            power(a, b);
            cout << res<< endl;
        }
    }

    return 0;
}