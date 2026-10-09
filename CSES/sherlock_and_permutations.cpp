//https://www.hackerrank.com/challenges/sherlock-and-permutations/problem
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */

using ll = long long;
const int mod = 1e9 + 7;
int N;
vector<ll> fac;
vector<ll> inv;
ll exponential(ll a , ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res * a % mod;
        b >>= 1;
        a = a  * a % mod;
    }
    return res;
}
void factorial(){
    fac.resize(N + 1);
    fac[0] = 1;
    for(int i = 1; i <= N; i++){
        fac[i] = fac[i-1] * i % mod;
    }
}

void inverse(){
    inv.resize(N+1);
    inv[N ] = exponential( fac[N ],  mod - 2) % mod;
    for(int i = N;i >= 1; i--){
        inv[i - 1] = inv[i] * i % mod;
    }
}

int solve(int n, int m) {
    N = n+m;
    int a = N- 1;
    factorial();
    inverse();
    int ans = fac[a] * inv[m - 1] % mod * inv[n] % mod;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int result = solve(n, m);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
