/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 *
 * https://leetcode.com/problems/candy/description/
 *
 * algorithms
 * Hard (29.73%)
 * Likes:    737
 * Dislikes: 149
 * Total Accepted:    120.7K
 * Total Submissions: 397.3K
 * Testcase Example:  '[1,0,2]'
 *
 * There are N children standing in a line. Each child is assigned a rating
 * value.
 * 
 * You are giving candies to these children subjected to the following
 * requirements:
 * 
 * 
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * 
 * 
 * What is the minimum candies you must give?
 * 
 * Example 1:
 * 
 * 
 * Input: [1,0,2]
 * Output: 5
 * Explanation: You can allocate to the first, second and third child with 2,
 * 1, 2 candies respectively.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,2]
 * Output: 4
 * Explanation: You can allocate to the first, second and third child with 1,
 * 2, 1 candies respectively.
 * ⁠            The third child gets 1 candy because it satisfies the above two
 * conditions.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = ratings.size();
        vector<int> rank_lr(n, 1);
        vector<int> rank_rl(n, 1);
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                rank_lr[i] = rank_lr[i - 1] + 1;
            } else {
                rank_lr[i] = 1;
            }

            if (ratings[n - i - 1] > ratings[n - i]) {
                rank_rl[n - i - 1] = rank_rl[n - i] + 1;
            } else {
                rank_rl[n - i - 1] = 1;
            }
        }
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += max(rank_lr[i], rank_rl[i]);
        }
        return s;
    }
};
// @lc code=end
