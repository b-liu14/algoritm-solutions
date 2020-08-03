/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (37.62%)
 * Likes:    3198
 * Dislikes: 78
 * Total Accepted:    271.6K
 * Total Submissions: 720.7K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 * 
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
    int min3(int a, int b, int c) {
        return min(min(a, b), c);
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) {
            return 0;
        }
        int m = matrix[0].size();
        int max_length = 0;
        int dp_left_up = 0;

        vector<int> dp(m, 0);
        for (int i = 0; i < n; i ++) {
            dp_left_up = dp[0];
            dp[0] = (matrix[i][0] == '1');
            max_length = max(max_length, dp[0]);
            for (int j = 1; j < m; j ++) {
                int tmp = dp[j];
                if (matrix[i][j] == '1') {
                    dp[j] = min3(dp[j], dp[j-1], dp_left_up) + 1;
                    max_length = max(max_length, dp[j]);
                }
                else {
                    dp[j] = 0;
                }
                dp_left_up = tmp;
            }
        }
        
        return max_length*max_length;
    }
};
// @lc code=end

int main() {
    vector<vector<char>> v = {{'1', '1', '1', '1', '1'}, 
                              {'1', '1', '1', '1', '1'},
                              {'0', '0', '0', '0', '0'},
                              {'1', '1', '1', '1', '1'},
                              {'1', '1', '1', '1', '1'},};
    Solution s;
    cout << s.maximalSquare(v) << endl;
}