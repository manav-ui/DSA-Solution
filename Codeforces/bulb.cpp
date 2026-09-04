//https://codeforces.com/contest/2020/problem/B
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long k;
        cin >> k;

        long long low = 1;
        long long high = 2e18;
        long long answer = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            // Number of perfect squares <= mid
            long long sq = sqrtl(mid);

            // Fix possible floating point precision errors
            while ((sq + 1) <= mid / (sq + 1))
                sq++;

            while (sq > mid / sq)
                sq--;

            // Number of bulbs still ON
            long long on = mid - sq;

            if (on >= k) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}