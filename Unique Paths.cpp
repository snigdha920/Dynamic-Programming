class Solution {
public:
    int paths[110][110];
    int uniquePaths(int m, int n) {
        memset(paths, -1, sizeof(paths));
        return calcUniquePaths(0, 0, m, n);
    }
    int calcUniquePaths(int r, int c, int m, int n) {
        if(r < 0 || c < 0 || r >= n || c >= m) return 0;
        if(r == n-1) return 1;
        if(c == m-1) return 1;
        if(paths[r][c] != -1) {
            return paths[r][c];
        }
        paths[r][c] = calcUniquePaths(r, c+1, m, n) + calcUniquePaths(r+1, c, m, n);
        return paths[r][c];
    }
};
