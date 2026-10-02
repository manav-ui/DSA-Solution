//https://codeforces.com/contest/602/problem/B
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    deque<int> mn, mx;

    int l = 0;
    int ans = 0;

    for (int r = 0; r < n; r++) {
        while (!mn.empty() && a[mn.back()] >= a[r])
            mn.pop_back();

        mn.push_back(r);
        while (!mx.empty() && a[mx.back()] <= a[r])
            mx.pop_back();

        mx.push_back(r);

        while (a[mx.front()] - a[mn.front()] > 1) {

            if (mn.front() == l)
                mn.pop_front();

            if (mx.front() == l)
                mx.pop_front();

            l++;
        }

        ans = max(ans, r - l + 1);
    }

    cout << ans << '\n';

    return 0;
}