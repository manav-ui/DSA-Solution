#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long k = (n * n + 1) / 2;

    long long low = 1, high = n * n;

    while (low < high) {
        long long mid = low + (high - low) / 2;

        long long cnt = 0;

        for (long long i = 1; i <= n; i++) {
            cnt += min(n, mid / i);
        }

        if (cnt >= k) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << '\n';

    return 0;
}