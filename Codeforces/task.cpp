//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, x, y;
    cin >> n >> x >> y;

    // Only one copy needed
    if (n == 1) {
        cout << min(x, y);
        return 0;
    }

    // Time needed to create the first copy
    long long firstCopy = min(x, y);

    // Binary search for remaining n-1 copies
    long long low = 0, high = (n - 1) * max(x, y);
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        long long copies = mid / x + mid / y;

        if (copies >= n - 1) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << firstCopy + ans;

    return 0;
}