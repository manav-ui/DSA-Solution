// https://cses.fi/problemset/task/1620
#include <bits/stdc++.h>
using namespace std;

bool check(long long days, vector<long long> &a, long long t) {
    long long products = 0;

    for (long long x : a) {
        products += days / x;

        if (products >= t)
            return true;
    }

    return false;
}

int main() {
    int n;
    long long t;

    cin >> n >> t;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long left = 0;
    long long right = (*min_element(a.begin(), a.end())) * t;

    long long ans = right;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (check(mid, a, t)) {
            ans = mid;
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}