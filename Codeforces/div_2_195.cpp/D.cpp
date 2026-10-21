
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> deg(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            cout << "Brain Melt\n";
            return;
        }
    }

    int mx = *max_element(deg.begin() + 1, deg.end());

    if (mx == n - 1 && m == n - 1) {
        cout << "2\n";
    } else {
        cout << "Many\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
