// O(m+n) spaces
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        vector<bool> row(m, false);
        vector<bool> column(n, false);
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    column[j] = true;
                }
            }
        }
        for (int i = 0; i < m; i ++) {
            if (row[i]) {
                for (int j = 0; j < n; j ++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < n; j ++) {
            if (column[j]) {
                for (int i = 0; i < m; i ++) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// O(1) spaces
class Solution {
public:
    void setRowZeroes(vector<vector<int>>& matrix, int row) {
        if (matrix.size()) {
            for (int i = 0; i < matrix[0].size(); i ++) {
                matrix[row][i] = 0;
            }
        }
    }
    void setColumnZeroes(vector<vector<int>>& matrix, int col) {
        for (int i = 0; i < matrix.size(); i ++) {
            matrix[i][col] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        int r = 0, c = 0;
        bool found = false;
        for (int i = 0; i < m; i ++) {
            if (found) break;
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j] == 0) {
                    r = i;
                    c = j;
                    found = true;
                    break;
                }
            }
        }
        if (! found) {
            return;
        }

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j] == 0) {
                    matrix[i][c] = 0;
                    matrix[r][j] = 0;
                }
            }
        }
        for (int i = 0; i < m; i ++) {
            if (matrix[i][c] == 0 && i != r) {
                setRowZeroes(matrix, i);
            }
        }
        for (int j = 0; j < n; j ++) {
            if (matrix[r][j] == 0 && j != c) {
                setColumnZeroes(matrix, j);
            }
        }
        setRowZeroes(matrix, r);
        setColumnZeroes(matrix, c);
    }
};
