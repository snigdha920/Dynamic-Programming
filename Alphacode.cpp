#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    while(true){
        string s; cin >> s;
        if(s[0] == '0') {
            break;
        }
        int n = s.length();
        ll dp[n];
        dp[0] = 1; 
        for(int i=1; i<n; i++) {
            int x = (s[i-1]-'0')*10 + (s[i]-'0');
            dp[i] = 0;
            if(x >= 10 && x <= 26) {
                if(i > 1) dp[i] += dp[i-2];
                else dp[i] = 1;
            } 
            if(s[i] != '0') dp[i] += dp[i-1];
            // cout << "at i: " << i << ", dp[" << i << "]: " << dp[i] << endl;
        }
        cout << dp[n-1] << endl;
    }
}
