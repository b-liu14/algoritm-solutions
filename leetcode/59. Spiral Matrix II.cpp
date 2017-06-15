class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int r = 0;
        int c = 0;
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        int direction = 0;
        for (int i = 0; i < n*n; i ++) {
            matrix[r][c] = i + 1;
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && matrix[nr][nc] == 0) {
                // do nothing.
            }
            else {
                direction = (direction + 1) % 4;
            }
            r = r + dr[direction];
            c = c + dc[direction];
        }
        return matrix;
    }
};
