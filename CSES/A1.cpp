/*
    Problem: Room Allocation
    Platform: CSES

    Link: https://cses.fi/problemset/task/1164/

    Topics: Sorting, Greedy, Priority Queue
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // {arrival, departure, original_index}
    vector<tuple<int, int, int>> customers;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        customers.push_back({a, b, i});
    }

    // Sort customers according to arrival time
    sort(customers.begin(), customers.end());

    // {departure_time, room_number}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    vector<int> ans(n);
    int rooms = 0;

    for (auto [arrival, departure, idx] : customers) {

        // Reuse the room if previous customer left earlier
        if (!pq.empty() && pq.top().first < arrival) {
            int room = pq.top().second;
            pq.pop();

            ans[idx] = room;
            pq.push({departure, room});
        } 
        else {
            // Need a new room
            rooms++;
            ans[idx] = rooms;
            pq.push({departure, rooms});
        }
    }

    cout << rooms << '\n';

    for (int room : ans) {
        cout << room << " ";
    }

    cout << '\n';

    return 0;
}