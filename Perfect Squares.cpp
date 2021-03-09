class Solution {
public:
    int memo[10010];
    int numSquares(int n) {
        memset(memo, -1, sizeof(memo));
        return solve(n);
    }
    int solve(int n) {
        if(n <= 3) return n;
        if(ceil(sqrt(n)) == floor(sqrt(n))) {
            return 1;
        }
        if(memo[n] != -1) return memo[n];
        int x, minVal = INT_MAX;
        for(int i=floor(sqrt(n)); i>=1; i--) {
            // cout << "i, n " << i << ", " << n << endl;
            if(i*i <= n) {
                x = i*i;
                minVal = min(minVal, 1 + solve(n-x));
            }
        }
        memo[n] = minVal;
        return memo[n];
    }
};
