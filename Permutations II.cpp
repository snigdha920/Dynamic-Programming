class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> count;
        int length = nums.size();
        for(int i=0; i<nums.size(); i++) {
            count[nums[i]]++;
        }
        return getAllUniquePerm(count, length, vector<int>());
    }
    vector<vector<int>> getAllUniquePerm(unordered_map<int, int>count, int length, vector<int>prefix) {
        vector<vector<int>> result;
        if(length == 0) {
            result.push_back(prefix);
            return result;
        }
        for(auto it = count.begin(); it != count.end(); it++) {
            if(it->second > 0) {
                it->second--;
                prefix.push_back(it->first);
                vector<vector<int>> tempRes = getAllUniquePerm(count, length-1, prefix);
                prefix.pop_back();
                it->second++;
                for(int i=0; i<tempRes.size(); i++) {
                    result.push_back(tempRes[i]);
                }
            }
        }
        return result;
    }
};
