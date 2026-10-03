#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, V;
    cin >> N >> V;

    vector<long long> W(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> W[i];
    }

    long long ans = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            for (int k = j + 1; k <= N; k++) {

                if (i + j + k <= V) {
                    ans = max(ans, W[i] + W[j] + W[k]);
                }

            }
        }
    }

    cout << ans << '\n';

    return 0;
}