class Solution {
public:
    unordered_map<int, int> dp;
    int calc(int n) {
        if(n <= 1) {
            return 1;
        }
        if(dp.find(n) != dp.end()) {
            return dp[n];
        }
        int ans = 0;
        for(int i=1; i<=n; i++) {
            ans += calc(i-1)*calc(n-i);
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        int ans = calc(n);
        return ans;
    }
};
