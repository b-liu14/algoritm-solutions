class Solution {
public:
    inline int get(vector<vector<int>>& npath, int i, int j) {
        if (i < 0 || j < 0) return 0;
        else return npath[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> npath(m, vector<int>(n, 1));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {

                if (obstacleGrid[i][j] == 1) npath[i][j] = 0;
                else if (i == 0 && j == 0) npath[i][j] = 1;
                else npath[i][j] = get(npath, i-1, j) + get(npath, i, j-1);
            }
        }
        return npath[m-1][n-1];
    }
};
