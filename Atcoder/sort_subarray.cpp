#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);

    for (auto &x : A)
        cin >> x;

    for (int L = 0; L + K <= N; L++) {
        vector<int> B = A;

        sort(B.begin() + L, B.begin() + L + K);

        if (is_sorted(B.begin(), B.end())) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";

    return 0;
}