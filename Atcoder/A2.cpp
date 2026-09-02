#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    vector<bitset<MAXN>> parity(N);

    for (int col = 0; col < M; col++) {

        vector<bitset<MAXN>> group(1000);

        for (int row = 0; row < N; row++) {
            group[A[row][col]].set(row);
        }

        for (int row = 0; row < N; row++) {
            parity[row] ^= group[A[row][col]];
        }
    }

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (parity[i][j]) ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}