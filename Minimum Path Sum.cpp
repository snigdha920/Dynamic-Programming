class Solution {
public:
    int memo[210][210];
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(memo, -1, sizeof(memo));
        return minPathSumSolve(m-1, n-1, grid);
    }
    int minPathSumSolve(int r, int c, vector<vector<int>>& grid) {
        if(r < 0 || c < 0) {
            return INT_MAX;
        }
        if(r == 0 && c == 0) {
            return grid[0][0];
        }
        if(memo[r][c] != -1) return memo[r][c];
        int path1 = minPathSumSolve(r, c-1, grid);
        int path2 = minPathSumSolve(r-1, c, grid);
        memo[r][c] = min(path1, path2) + grid[r][c];
        return memo[r][c];
    }
};
