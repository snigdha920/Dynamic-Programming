class Solution {
public:
    unordered_map<string, int> memo;
    vector<int> a;
    string getKey(int x, bool y, int z) {
        string key = "";
        key += to_string(x) + "_" + to_string(y) + "_" + to_string(z);
        return key;
    }
    int max3(int a, int b, int c) {
        return max(a, max(b, c));
    }
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            a.push_back(nums[i]);
        }
        return getMaxProduct(n, true, 1);
    }
    int getMaxProduct(int n, bool first, int curProd) {
        if(n == 1) {
            if(first) {
                return a[0];
            }
            return max3(a[0], curProd*a[0], curProd);
        }
        string key = getKey(n, first, curProd);
        if(memo.find(key) != memo.end()) return memo[key];
        int result = INT_MIN, includeElement, excludeElement, startFromElement = 0;
        includeElement = getMaxProduct(n-1, false, curProd*a[n-1]);
        startFromElement = getMaxProduct(n-1, false, a[n-1]);
        excludeElement = getMaxProduct(n-1, true, 1);
        if(a[n-1] > 0) {
            result = max(includeElement, startFromElement);
        } else if(a[n-1] == 0) {
            if(first) {
                result = max(excludeElement, 0);
            } else {
                result = max3(0, excludeElement, curProd);
            }
        } else {
            if(first) {
                result = max3(excludeElement, a[n-1], startFromElement);
            } else {
                result = max3(startFromElement, max(excludeElement, includeElement), max(curProd, a[n-1]));
            }
        }
        memo[key] = result;
        return result;
    }
};
