#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        ll l, r;
        cin >> l >> r;
        ll prev ;
        int i = 0;
        while(l <= r){
            prev = l;
            l |= (1LL << i);
            i++;
        }
        cout << prev << endl;
    }

    return 0;
}