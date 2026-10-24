#include<bits/stdc++.h>
using namespace std;
void solve(){
    int q;
    cin >> q;
    int id = 1;
    unordered_map<string, int> map;
    for(int i = 0; i < q; i++){
        string s ;
        cin >> s;
        auto it = map.find(s);

        if(it == map.end()) {
            map[s] = id;
            cout << (id++) << endl;

        }
        else cout << it->second << endl;
    }
}
int main(){
    solve();
    return 0;
}