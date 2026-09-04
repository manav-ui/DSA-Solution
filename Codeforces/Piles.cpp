//https://codeforces.com/contest/1807/problem/E
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

        vector<long long> a(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int low = 1;
        int high = n;

        while (low < high) {
            int mid = (low + high) / 2;

            long long expectedSum = 0;

            for (int i = low; i <= mid; i++) {
                expectedSum += a[i];
            }

            cout << "? " << (mid - low + 1) << " ";

            for (int i = low; i <= mid; i++) {
                cout << i << " ";
            }

            cout << endl; 
            long long actualSum;
            cin >> actualSum;
            if (actualSum > expectedSum) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        cout << "! " << low << endl;
    }

    return 0;
}