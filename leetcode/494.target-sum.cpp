/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (46.01%)
 * Likes:    2984
 * Dislikes: 120
 * Total Accepted:    182.7K
 * Total Submissions: 396.3K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.
 * 
 * Example 1:
 * 
 * 
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The length of the given array is positive and will not exceed 20.
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 * 
 * 
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

// dynamic programming
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int S) {
//         if (S > 1000 || S < -1000)
//             return 0;
//         int dp[21][2001];
//         memset(dp, 0, sizeof(dp));
//         // dp[i][j]: number of ways to assign first i elements to get target j - 1000
//         dp[0][0 + 1000] = 1;
//         for (int i = 1; i <= nums.size(); i++) {
//             for (int j = 0; j < 2001; j++) {
//                 dp[i][j] = 0;
//                 if (j + nums[i - 1] < 2001) {
//                     dp[i][j] += dp[i - 1][j + nums[i - 1]];
//                 }
//                 if (j - nums[i - 1] > 0) {
//                     dp[i][j] += dp[i - 1][j - nums[i - 1]];
//                 }
//             }
//         }
//         return dp[nums.size()][S + 1000];
//     }
// };

// forward
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int S) {
//         if (S > 1000 || S < -1000)
//             return 0;
//         map<int, int> ways;
//         ways[0] = 1;
//         for (int i = 1; i <= nums.size(); i++) {
//             map<int, int> tmp = ways;
//             ways.clear();
//             for (auto& iter : tmp) {
//                 int k = iter.first;
//                 int v = iter.second;
//                 ways[k - nums[i - 1]] += v;
//                 ways[k + nums[i - 1]] += v;
//             }
//         }
//         return ways[S];
//     }
// };

// @lc code=start
// dfs with memorization
class Solution {
    // pair (index, sum) to count
    map<pair<int, int>, int> dp;

public:
    int dfs(vector<int>& nums, int i, int S) {
        if (nums.size() == i) {
            return S == 0;
        }
        auto p = make_pair(i, S);
        if (dp.find(p) == dp.end()) {
            dp[p] = dfs(nums, i + 1, S - nums[i]) + dfs(nums, i + 1, S + nums[i]);
        }
        return dp[p];
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        if (S > 1000 || S < -1000)
            return 0;
        return dfs(nums, 0, S);
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums{1, 1, 1, 0, 1, 1};
    cout << s.findTargetSumWays(nums, 3);

    return 0;
}