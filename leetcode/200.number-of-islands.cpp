/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (43.68%)
 * Likes:    4224
 * Dislikes: 157
 * Total Accepted:    559.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of
 * islands. An island is surrounded by water and is formed by connecting
 * adjacent lands horizontally or vertically. You may assume all four edges of
 * the grid are all surrounded by water.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * 11110
 * 11010
 * 11000
 * 00000
 * 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * 11000
 * 11000
 * 00100
 * 00011
 * 
 * Output: 3
 * 
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, 1, -1, 0};
    void dfs(vector<vector<char>>& grid, int x, int y, int n, int m) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            auto x1 = x + dx[i];
            auto y1 = y + dy[i];
            if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) {
                continue;
            }
            if (grid[x1][y1] == '1') {
                dfs(grid, x1, y1, n, m);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) {
            return 0;
        }
        int m = grid[0].size();

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j, n, m);
                }
            }
        }
        return cnt;
    }
};
// @lc code=end
