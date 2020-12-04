#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll max(ll &a, ll &b) {
    if(a > b) return a;
    else return b;
}

unordered_map<ll, ll> dp;
ll maxdollars(ll n) {
    if(n <= 3) return n;
    if(dp.find(n) != dp.end()) return dp[n];
    return dp[n] = max(n, maxdollars(n/2)+maxdollars(n/3)+maxdollars(n/4));
}
int main() {
    ll x; 
    while(cin >> x) {
        dp = unordered_map<ll, ll>();
        ll val = maxdollars(x);
        cout << val << endl;
    }
}
