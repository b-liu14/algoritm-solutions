/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (39.60%)
 * Likes:    1774
 * Dislikes: 91
 * Total Accepted:    185.4K
 * Total Submissions: 430.9K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * Empty cells are indicated by the character '.'.
 * 
 * 
 * A sudoku puzzle...
 * 
 * 
 * ...and its solution numbers marked in red.
 * 
 * Note:
 * 
 * 
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique
 * solution.
 * The given board size is always 9x9.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool dfs(vector<vector<char>>& board, int n) {
        if (n >= 9 * 9) {
            return true;
        }
        int i = n / 9;
        int j = n % 9;
        char& cij = board[i][j];
        if (cij != '.') {
            return dfs(board, n + 1);
        }
        for (char c = '1'; c <= '9'; c++) {
            int k = 0;
            for (; k < 9; k++) {
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
// @lc code=end
