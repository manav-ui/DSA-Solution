// https://cses.fi/problemset/task/1643/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long total = 0;
    long long ans = LLONG_MIN;

    for(int i = 0; i < n; i++){
        int a ; cin >> a;
        total += a;
        ans = max(total , ans);
        if(total < 0) total = 0;
    }
    cout << ans;
}