#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    bitset<10001> dp;
    dp[0] = 1;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        dp = (dp << a) | (dp << b);
    }

    cout << (dp[X] ? "Yes" : "No") << '\n';

    return 0;
}