/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 *
 * https://leetcode.com/problems/dungeon-game/description/
 *
 * algorithms
 * Hard (28.40%)
 * Likes:    1608
 * Dislikes: 37
 * Total Accepted:    105.2K
 * Total Submissions: 329.6K
 * Testcase Example:  '[[-2,-3,3],[-5,-10,1],[10,30,-5]]'
 *
 * table.dungeon, .dungeon th, .dungeon td {
 * ⁠ border:3px solid black;
 * }
 * 
 * ⁠.dungeon th, .dungeon td {
 * ⁠   text-align: center;
 * ⁠   height: 70px;
 * ⁠   width: 70px;
 * }
 * 
 * The demons had captured the princess (P) and imprisoned her in the
 * bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid
 * out in a 2D grid. Our valiant knight (K) was initially positioned in the
 * top-left room and must fight his way through the dungeon to rescue the
 * princess.
 * 
 * The knight has an initial health point represented by a positive integer. If
 * at any point his health point drops to 0 or below, he dies immediately.
 * 
 * Some of the rooms are guarded by demons, so the knight loses health
 * (negative integers) upon entering these rooms; other rooms are either empty
 * (0's) or contain magic orbs that increase the knight's health (positive
 * integers).
 * 
 * In order to reach the princess as quickly as possible, the knight decides to
 * move only rightward or downward in each step.
 * 
 * 
 * 
 * Write a function to determine the knight's minimum initial health so that he
 * is able to rescue the princess.
 * 
 * For example, given the dungeon below, the initial health of the knight must
 * be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN ->
 * DOWN.
 * 
 * 
 * 
 * 
 * -2 (K)
 * -3
 * 3
 * 
 * 
 * -5
 * -10
 * 1
 * 
 * 
 * 10
 * 30
 * -5 (P)
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The knight's health has no upper bound.
 * Any room can contain threats or power-ups, even the first room the knight
 * enters and the bottom-right room where the princess is imprisoned.
 * 
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

// binary search the minimum HP
// class Solution {
// public:
//     // TODO: 剪枝
//     bool canPass(int HP, vector<vector<int>>& dungeon) {
//         int M = dungeon.size(), N = dungeon[0].size();
//         vector<vector<long long>> dp(M, vector<long long>(N, 0));
//         dp[0][0] = dungeon[0][0] + HP;
//         if (dp[0][0] <= 0) {
//             return false;
//         }

//         for (int i = 0; i < M; i++) {
//             for (int j = 0; j < N; j++) {
//                 if (i == 0 && j == 0) {
//                     continue;
//                 }

//                 long long prev_hp = INT_MIN;
//                 if (i > 0) {
//                     prev_hp = max(prev_hp, dp[i - 1][j]);
//                 }
//                 if (j > 0) {
//                     prev_hp = max(prev_hp, dp[i][j - 1]);
//                 }

//                 if (prev_hp <= 0) {
//                     dp[i][j] = INT_MIN;
//                 } else {
//                     dp[i][j] = prev_hp + dungeon[i][j];
//                 }
//             }
//         }

//         return dp.back().back() > 0;
//     }

//     int calculateMinimumHP(vector<vector<int>>& dungeon) {
//         // if only one room
//         if (dungeon.size() == 1 && dungeon[0].size() == 1) {
//             return max(1, -dungeon[0][0]);
//         }

//         // binary search minimum HP from 0 to INT_MAX
//         int min_ = 0, max_ = INT_MAX;
//         while (max_ > min_ + 1) {
//             int middle = (max_ - min_) / 2 + min_;
//             if (canPass(middle, dungeon)) {
//                 max_ = middle;
//             } else {
//                 min_ = middle;
//             }
//         }
//         return max_;
//     }
// };

// dynamic programming in reverse direction
// space: O(nm)
// class Solution {
// public:
//     int calculateMinimumHP(vector<vector<int>>& dungeon) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         cout.tie(NULL);
//         int m = dungeon.size(), n = dungeon[0].size();
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
//         dp[m][n - 1] = 1;
//         dp[m - 1][n] = 1;
//         for (int i = m - 1; i >= 0; i--) {
//             for (int j = n - 1; j >= 0; j--) {
//                 dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
//             }
//         }
//         return dp[0][0];
//     }
// };

// @lc code=start
// dynamic programming in reverse direction
// space compexity: O(N)
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n - 1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                dp[j] = max(1, min(dp[j], dp[j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0];
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    cout << s.calculateMinimumHP(dungeon);

    return 0;
}