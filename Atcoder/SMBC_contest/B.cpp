#include<bits/stdc++.h>
using namespace std;
void solve(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(auto &it: A){
        cin >> it;
    }
    int count = 0;
    for(int i = 0; i < N;i++){
        if(A[i] == K) count++;
    }
    for(int i = 0; i < N -1; i++){
        if((A[i] < K && A[i+1] > K) ||(A[i] > K && A[i+1] < K)) count++;
    }
    cout << count << endl;
}
int main(){
    solve();
    return 0;
}