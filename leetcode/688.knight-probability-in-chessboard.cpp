/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 *
 * https://leetcode.com/problems/knight-probability-in-chessboard/description/
 *
 * algorithms
 * Medium (46.35%)
 * Likes:    921
 * Dislikes: 182
 * Total Accepted:    46.5K
 * Total Submissions: 94.5K
 * Testcase Example:  '3\n2\n0\n0'
 *
 * On an NxN chessboard, a knight starts at the r-th row and c-th column and
 * attempts to make exactly K moves. The rows and columns are 0 indexed, so the
 * top-left square is (0, 0), and the bottom-right square is (N-1, N-1).
 * 
 * A chess knight has 8 possible moves it can make, as illustrated below. Each
 * move is two squares in a cardinal direction, then one square in an
 * orthogonal direction.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Each time the knight is to move, it chooses one of eight possible moves
 * uniformly at random (even if the piece would go off the chessboard) and
 * moves there.
 * 
 * The knight continues moving until it has made exactly K moves or has moved
 * off the chessboard. Return the probability that the knight remains on the
 * board after it has stopped moving.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: 3, 2, 0, 0
 * Output: 0.0625
 * Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight
 * on the board.
 * From each of those positions, there are also two moves that will keep the
 * knight on the board.
 * The total probability the knight stays on the board is 0.0625.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * N will be between 1 and 25.
 * K will be between 0 and 100.
 * The knight always initially starts on the board.
 * 
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
// memorization search
class Solution {
    double dp[27][27][102];
    // 8 direction
    int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

public:
    double dfs(int N, int K, int r, int c) {
        // out of chessboard
        if (r < 0 || c < 0 || r >= N || c >= N) {
            return 0;
        }
        // no move
        else if (K == 0) {
            return 1;
        }
        // no memory, calcluate it
        else if (dp[r][c][K] == 0) {
            dp[r][c][K] = 0;
            for (int i = 0; i < 8; i++) {
                dp[r][c][K] += dfs(N, K - 1, r + dx[i], c + dy[i]) / 8.0;
            }
        }
        return dp[r][c][K];
    }
    double knightProbability(int N, int K, int r, int c) {
        // for (int i = 0; i <= K; i++) {
        //     dp.push_back(vector<vector<double>>(N, vector<double>(N, -1)));
        // }
        memset(dp, 0, sizeof(dp));
        return dfs(N, K, r, c);
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.knightProbability(3, 1, 1, 1) << endl;
}