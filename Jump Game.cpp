class Solution {
public:
    vector<int> a;
    int memo[30010];
    bool canJump(vector<int>& nums) {
        memset(memo, -1, sizeof(memo));
        for(int i=0; i<nums.size(); i++) {
            a.push_back(nums[i]);
        }
        return cannJump(a.size() - 1);
    }
    bool cannJump(int dest) {
        if(dest == 0) return true;
        if(memo[dest] != -1) return memo[dest];
        bool result = false;
        for(int i=dest-1; i>=0; i--) {
            if(a[i] >= dest-i) {
                result = cannJump(i);
            }
            if(result) {
                break;
            }
        }
        memo[dest] = result;
        return result;
    }
};
