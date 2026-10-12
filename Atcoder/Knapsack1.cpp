#include<bits/stdc++.h>
using namespace std;
void solve(){
  int n, m;
  cin >> n >> m;
  int remainder = m %n;
  int multiple = m/n;
  for(int i = 0; i < n; i++){
    int a = multiple ;
    if(remainder!= 0){
        a += 1; 
        remainder--;
    }
    cout << a << endl;
  }
}
int main(){
  solve();
  return 0;
}