class Solution {
public:
    bool dfs(vector<vector<char>>& board, int n) {
        if (n >= 9*9) {
            return true;
        }
        int i = n / 9;
        int j = n % 9;
        char &cij = board[i][j];
        if (cij != '.') {
            return dfs(board, n + 1);
        }
        for (char c = '1'; c <= '9'; c ++) {
            int k = 0;
            for (; k < 9; k ++) {
                if (board[i][k] == c || board[k][j] == c ||
                    board[i - i % 3 + k / 3][j - j % 3 + k % 3] == c) {
                    break;
                }
            }
            // valid?
            if (k == 9) {
                cij = c;
                if (dfs(board, n + 1)) {
                    return true;
                }
                cij = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0);
    }
};
