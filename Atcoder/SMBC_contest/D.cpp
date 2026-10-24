#include<bits/stdc++.h>
using namespace std;
void solve(){
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    vector<vector<int>> adj(N+1);
    for(int i = 0; i < M; i++){
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);

    }

    for(int i = 1; i <= N; i++){
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }
    const int INF = 1e9;
    vector<int> min_fuel(N+1, INF);
    deque<int> dq;
    min_fuel[S] = 0;
    dq.push_front(S);
    while(!dq.empty()){
        int u = dq.front();
        dq.pop_front();
        if(u == T){
            cout << min_fuel[T] << endl;
            return ;
        }
        if(adj[u].empty()) continue;
        int neighbour = adj[u][0];
        if(min_fuel[u] + 0 < min_fuel[neighbour]){
            min_fuel[neighbour] = min_fuel[u];
            dq.push_front(neighbour);
        }
        for(size_t i = 1; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(min_fuel[u] + 1 < min_fuel[v]){
                min_fuel[v] = min_fuel[u] + 1;
                dq.push_back(v);
            }
        }
    }

    cout << (min_fuel[T] == INF? -1 : min_fuel[T]) << endl;
}
int main(){
    solve();
    return 0;
}