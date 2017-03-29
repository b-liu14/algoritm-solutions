class Solution {
public:
    inline int get(vector<vector<int>>& v, int i, int j) {
        if (i < 0 || j < 0) return INT_MAX;
        else return v[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (i == 0 && j == 0) continue;
                grid[i][j] += min(get(grid, i-1, j), get(grid, i, j-1));
            }
        }
        return grid.back().back();
    }
};
