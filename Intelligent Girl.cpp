#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; cin >> s;
	int l = s.length();
	int dp[l+1]; dp[l] = 0;
	for(int i=l-1; i>=0; i--) {
		if((s[i]-'0') % 2) dp[i] = dp[i+1];
		else dp[i] = dp[i+1] + 1;
	}
	for(int i=0; i<l; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;
}
