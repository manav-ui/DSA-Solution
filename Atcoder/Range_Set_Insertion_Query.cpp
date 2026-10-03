#include <bits/stdc++.h>
using namespace std;

int l, r, x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> values(N+2);
    for(int i = 0; i < Q; i++){
        cin >> l >> r >> x;
        values[l].push_back(x);
        values[r+1].push_back(-x);
    }
    unordered_map<int,int> map;
    unordered_set<int> st;
    for(int i = 1; i < values.size() - 1 ; i++){
        for(auto k : values[i]){
            if(k > 0){
                st.insert(k);
                map[k]++;
            }else{
                k = abs(k);
                map[k]--;
                if(map[k] == 0) st.erase(k);
            }
        }
        cout << st.size()<<" ";
    }
    return 0;

}