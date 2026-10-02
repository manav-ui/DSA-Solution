#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> arrival(n), leaving(n);

    for (int i = 0; i < n; i++) {
        cin >> arrival[i] >> leaving[i];
    }

    sort(arrival.begin(), arrival.end());
    sort(leaving.begin(), leaving.end());

    int i = 0, j = 0;
    int curr = 0, ans = 0;

    while (i < n) {
        if (arrival[i] < leaving[j]) {
            curr++;
            ans = max(ans, curr);
            i++;
        } else {
            curr--;
            j++;
        }
    }

    cout << ans << '\n';
}

int main() {
    solve();
    return 0;
}