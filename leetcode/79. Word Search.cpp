class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int x, int y, int n) {
        if (word[n] != board[x][y]) {
            return false;
        }
        if (n == word.length() - 1) {
            return true;
        }
        char c = board[x][y];
        board[x][y] = '#'; // visited
        if (x > 0 && dfs(board, word, x-1, y, n+1)) return true;
        if (y > 0 && dfs(board, word, x, y-1, n+1)) return true;
        if (x < board.size() - 1 && dfs(board, word, x+1, y, n+1)) return true;
        if (y < board[0].size() - 1 && dfs(board, word, x, y+1, n+1)) return true;
        board[x][y] = c;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[0].size(); j ++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
