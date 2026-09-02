#include <bits/stdc++.h>
using namespace std;

int main() {
    double c;
    cin >> c;
    double low = 0;
    double high = 100000;
    for (int i = 0; i < 100; i++) {
        double mid = (low + high) / 2.0;
        double value = mid * mid + sqrt(mid);
        if (value < c) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    cout << fixed << setprecision(10) << low;

    return 0;
}