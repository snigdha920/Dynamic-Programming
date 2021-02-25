class Solution {
public:
    vector<int> a;
    int memo[2503][2503];
    int lengthOfLIS(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        for(int &n : nums) a.push_back(n);
        a.push_back(INT_MAX);
        return LIS(a.size()-1, a.size());
    }

    int LIS(int n, int lastChosen) {
        if(n <= 0 || lastChosen <= 0) return 0;
        if(memo[n][lastChosen] != -1) return memo[n][lastChosen];
        int choosen = INT_MIN;
        if(a[n-1] < a[lastChosen-1]) {
            choosen = LIS(n-1, n) + 1;
        } 
        int notChosen = LIS(n-1, lastChosen);
        memo[n][lastChosen] = max(choosen, notChosen);
        return memo[n][lastChosen];
    }
};
