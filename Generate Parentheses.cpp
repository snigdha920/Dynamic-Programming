class Solution {
public:
    vector<string> generateParenthesis(int n) {
        n *= 2;
        unordered_map<int, vector<string>> par;
        vector<string> t;
        t.push_back("");
        par[0] = t;
        // cout << par[0].size();
        t.clear(); t.push_back("()");
        par[2] = t;
        for(int i=4; i<=n; i+=2) {
            t.clear();
            for(int j=1; j<i; j+=2) {
                for(int x=0; x<par[j-1].size(); x++) {
                    string temp = "()";
                    temp.insert(1, par[j-1][x]);
                    // cout << "temp is " << temp << " at i = " << i << " and j = " << j << endl;
                    for(int y=0; y<par[i-1-j].size(); y++) {
                        string tempy = temp;
                        tempy.append(par[i-1-j][y]);
                        // cout << "tempy is " << tempy << endl;
                        t.push_back(tempy);
                    }
                }
            }
            par[i] = t;
        }
        return t;
    }
};
