/*
 * @lc app=leetcode id=1222 lang=cpp
 *
 * [1222] Queens That Can Attack the King
 *
 * https://leetcode.com/problems/queens-that-can-attack-the-king/description/
 *
 * algorithms
 * Medium (68.58%)
 * Likes:    227
 * Dislikes: 59
 * Total Accepted:    15.7K
 * Total Submissions: 23K
 * Testcase Example:  '[[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]]\n[0,0]'
 *
 * On an 8x8 chessboard, there can be multiple Black Queens and one White
 * King.
 * 
 * Given an array of integer coordinates queens that represents the positions
 * of the Black Queens, and a pair of coordinates king that represent the
 * position of the White King, return the coordinates of all the queens (in any
 * order) that can attack the King.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
 * Output: [[0,1],[1,0],[3,3]]
 * Explanation:  
 * The queen at [0,1] can attack the king cause they're in the same row. 
 * The queen at [1,0] can attack the king cause they're in the same column. 
 * The queen at [3,3] can attack the king cause they're in the same diagnal. 
 * The queen at [0,4] can't attack the king cause it's blocked by the queen at
 * [0,1]. 
 * The queen at [4,0] can't attack the king cause it's blocked by the queen at
 * [1,0]. 
 * The queen at [2,4] can't attack the king cause it's not in the same
 * row/column/diagnal as the king.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]], king = [3,3]
 * Output: [[2,2],[3,4],[4,4]]
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: queens =
 * [[5,6],[7,7],[2,1],[0,7],[1,6],[5,1],[3,7],[0,3],[4,0],[1,2],[6,3],[5,0],[0,4],[2,2],[1,1],[6,4],[5,4],[0,0],[2,6],[4,5],[5,2],[1,4],[7,5],[2,3],[0,5],[4,2],[1,0],[2,7],[0,1],[4,6],[6,1],[0,6],[4,3],[1,7]],
 * king = [3,4]
 * Output: [[2,3],[1,4],[1,6],[3,7],[4,3],[5,4],[4,5]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= queens.length <= 63
 * queens[0].length == 2
 * 0 <= queens[i][j] < 8
 * king.length == 2
 * 0 <= king[0], king[1] < 8
 * At most one piece is allowed in a cell.
 * 
 * 
 */

#include <iostream>
#include <pair>
#include <set>
#include <vector>
using namespace std;

// @lc code=start
#define SIZE 8
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> result;

        set<pair<int, int>> s;
        for (auto& queen : queens) {
            s.insert(make_pair(queen[0], queen[1]));
        }
        int x = king[0], y = king[1];
        // 8 direction: left, right, up, down, up left, up right, down left, down right
        int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
        int dy[8] = {0, 0, -1, 1, -1, -1, 1, 1};
        // for each direction
        for (int i = 0; i < 8; i++) {
            // for each step
            for (int j = 1; j < SIZE; j++) {
                // new attack location
                int x1 = x + dx[i] * j;
                int y1 = y + dy[i] * j;

                // if out of range, break
                if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE) {
                    break;
                }

                // check
                if (s.find(make_pair(x1, y1)) != s.end()) {
                    result.push_back(vector<int>{x1, y1});
                    break;  // only one queue in one direction can attack the king
                }
            }
        }
        return result;
    }
};
// @lc code=end
