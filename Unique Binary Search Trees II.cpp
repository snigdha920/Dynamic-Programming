/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<int> bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()) {
            TreeNode* x = q.front();
            q.pop();
            if(x) ans.push_back(x->val);
            else {
                ans.push_back(0);
                continue;
            }
            q.push(x->left);
            q.push(x->right);
        }
        return ans;
    }
    void insertNode(int v, TreeNode* root) {
        if(v == 0) return;
        if(v > root->val) {
            if(root->right) {
                insertNode(v, root->right);
            }
            else {
                TreeNode* newNode = new TreeNode(v);
                root->right = newNode;
                return;
            }
        } else {
            if(root->left) {
                insertNode(v, root->left);
            }
            else {
                TreeNode* newNode = new TreeNode(v);
                root->left = newNode;
                return;
            }
        }
    }
    vector<TreeNode*> generateTrees(int n) {
        unordered_map<int, vector<vector<int>>> trees;
        vector<vector<int>>temp;
        temp.push_back({1});
        trees[1] = temp;
        vector<vector<int>>temp1;
        temp.push_back({});
        trees[0] = temp1;
        vector<vector<int>>tree;
        for(int i=2; i<=n; i++) {
            tree.clear();
            for(int j=1; j<=i; j++) {
                for(int k=0; k<trees[j-1].size(); k++) {
                    TreeNode* root = new TreeNode(j);
                    for(int x=0; x<trees[j-1][k].size(); x++) {
                        if(trees[j-1][k][x] == 0) continue;
                        insertNode(trees[j-1][k][x], root);
                    }
                    if(trees[i-j].size() == 0) {
                        vector<int> tempTree = bfs(root);
                        tree.push_back(tempTree);
                        // printf("at j = %d, i = %d\n", j, i);
                        // for(int c=0; c<tempTree.size(); c++) {
                        //     cout << tempTree[c] << " ";
                        // }
                        // cout << endl;
                        root->right = nullptr;
                        continue;
                    }
                    for(int k1=0; k1<trees[i-j].size(); k1++) {
                        for(int y=0; y<trees[i-j][k1].size(); y++) {
                            if(trees[i-j][k1][y] == 0) continue;
                            insertNode(trees[i-j][k1][y]+j, root);
                        }
                        vector<int> tempTree = bfs(root);
                        // printf("at j = %d, i = %d\n", j, i);
                        // for(int c=0; c<tempTree.size(); c++) {
                        //     cout << tempTree[c] << " ";
                        // }
                        // cout << endl;
                        tree.push_back(tempTree);
                        root->right = nullptr;
                    }
                    root->left = nullptr;
                }  
                if(trees[j-1].size() == 0) {
                    TreeNode* root = new TreeNode(j);
                    for(int k1=0; k1<trees[i-j].size(); k1++) {
                        for(int y=0; y<trees[i-j][k1].size(); y++) {
                            if(trees[i-j][k1][y] == 0) continue;
                            insertNode(trees[i-j][k1][y]+j, root);
                        }
                        vector<int> tempTree = bfs(root);
                        // printf("at j = %d, i = %d\n", j, i);
                        // for(int c=0; c<tempTree.size(); c++) {
                        //     cout << tempTree[c] << " ";
                        // }
                        // cout << endl;
                        tree.push_back(tempTree);
                        root->right = nullptr;
                    }
                }
            }
            // cout << "size of tree at i = " << i << " is " << tree.size() << endl;
            trees[i] = tree;
            cout << "size of tree at i = " << i << " is " << trees[i].size() << endl;
        }  
        cout << "*********" << endl;
        vector<TreeNode*> dummy;
        for(int i=0; i<trees[n].size(); i++) {
            TreeNode* root = new TreeNode(trees[n][i][0]);
            for(int j=1; j<trees[n][i].size(); j++) {
                if(trees[n][i][j] == 0) continue;
                else {
                    insertNode(trees[n][i][j], root);
                }
            }
            dummy.push_back(root);
            // cout << endl;
        }
        
        return dummy;
    }
};
