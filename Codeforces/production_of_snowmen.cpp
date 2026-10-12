
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n), c(n);

        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        for (int &x : c) cin >> x;

        ll ab = 0, bc = 0;

        for (int s = 0; s < n; s++) {
            bool okAB = true;
            bool okBC = true;

            for (int i = 0; i < n; i++) {
                if (a[i] >= b[(i + s) % n])
                    okAB = false;

                if (b[i] >= c[(i + s) % n])
                    okBC = false;
            }

            if (okAB) ab++;
            if (okBC) bc++;
        }

        cout << ab * bc << '\n';
    }

    return 0;
}
