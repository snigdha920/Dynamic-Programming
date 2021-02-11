class Solution {
public:
    int memo[5010][510];
    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        if(coins.size() == 0) return 0;
        memset(memo, -1, sizeof(memo));
        return makeChange(amount, coins, 0);
    }
    int makeChange(int amount, vector<int>& coins, int index) {
        if(index+1 >= coins.size()) {
            return amount%coins[index] == 0;
        }
        if(memo[amount][index] != -1) {
            return memo[amount][index];
        }
        int denomAmount = coins[index], ways = 0;
        for(int i=0; i*denomAmount <= amount; i++) {
            int amountRemaining = amount - i*denomAmount;
            ways += makeChange(amountRemaining, coins, index+1);
        }
        memo[amount][index] = ways;
        return ways;
    }
};
