class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        if (m == 0) return ans;
        int n = matrix[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        int r = 0;
        int c = 0;
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        int direction = 0;
        for (int i = 0; i < m*n; i ++) {

            ans.push_back(matrix[r][c]);
            used[r][c] = true;

            int nr = r + dr[direction];
            int nc = c + dc[direction];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !used[nr][nc]) {
                // do nothing.
            }
            else {
                direction = (direction + 1) % 4;
            }
            r = r + dr[direction];
            c = c + dc[direction];
        }
        return ans;
    }
};
