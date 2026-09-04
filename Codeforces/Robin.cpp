#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        // Impossible for n = 1 or n = 2
        if (n <= 2) {
            cout << -1 << '\n';
            continue;
        }

        // Sort to find the required median-like element
        sort(a.begin(), a.end());

        // We need a[n/2] to become unhappy
        long long x = 2LL * n * a[n / 2] - sum + 1;

        // x cannot be negative
        cout << max(0LL, x) << '\n';
    }

    return 0;
}