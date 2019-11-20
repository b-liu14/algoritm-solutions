/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (35.36%)
 * Likes:    1469
 * Dislikes: 59
 * Total Accepted:    175.8K
 * Total Submissions: 497.1K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * Say you have an array for which the i^th element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit
 * = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 =
 * 3.
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are
 * engaging multiple transactions at the same time. You must sell before buying
 * again.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     if (n < 2) return 0;

    //     int min_ = prices[0], max_ = prices[n - 1];
    //     vector<int> prof_left(n, 0), prof_right(n, 0);
    //     for (int i = 1; i < n; i ++) {
    //         prof_left[i] = max(prof_left[i-1], prices[i] - min_);
    //         min_ = min(min_, prices[i]);
    //         prof_right[n - i - 1] = max(prof_right[n - i], max_ - prices[n - i - 1]);
    //         max_ = max(max_, prices[n - i - 1]);
    //     }

    //     int profit = prof_left[n - 1];
    //     for (int i = 0; i < n - 1; i++) {
    //         profit = max(profit, prof_left[i] + prof_right[i+1]);
    //     }
    //     return profit;
    // }

    // elegant dynamic programming solution
    int maxProfit(vector<int>& prices) {
        vector<int> dp({INT_MIN, 0, INT_MIN, 0});
        for (int i = 0; i < prices.size(); ++i) {
            dp[3] = max(dp[3], dp[2] + prices[i]);  // dp[0]: - t1_buy
            dp[2] = max(dp[2], dp[1] - prices[i]);  // dp[1]: - t1_buy + t1_sell
            dp[1] = max(dp[1], dp[0] + prices[i]);  // dp[2]: - t1_buy + t1_sell - t2_buy
            dp[0] = max(dp[0], -prices[i]);         // dp[3]: - t1_buy + t1_sell - t2_buy + t2_sell
        }
        return dp[3];
    }
};
// @lc code=end
