class Solution {
public:
    int paths[110][110];
    int uniquePaths(int m, int n) {
        memset(paths, -1, sizeof(paths));
        return calcUniquePaths(m-1, n-1, m, n);
    }
    int calcUniquePaths(int r, int c, int m, int n) {
        if(r < 0 || c < 0) return 0;
        if(r == 0 || c == 0) return 1;
        if(paths[r][c] != -1) {
            printf("path[%d][%d]: %d", r, c, paths[r][c]);
            return paths[r][c];
        }
        
        paths[r][c] = calcUniquePaths(r-1, c, m, n) + calcUniquePaths(r, c-1, m, n);
        printf("path[%d][%d]: %d", r, c, paths[r][c]);
        return paths[r][c];
    }
};
