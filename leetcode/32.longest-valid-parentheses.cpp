/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (26.74%)
 * Likes:    3391
 * Dislikes: 132
 * Total Accepted:    281.8K
 * Total Submissions: 1M
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */

// @lc code=start
// my solution using map
// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int nLeft = 0;
//         int ans = 0;
//         map<int, int> left;
//         left[0] = -1;
//         for (int i = 0; i < s.length(); i++) {
//             if (s[i] == '(') {
//                 nLeft++;
//                 if (left.find(nLeft) == left.end()) {
//                     left[nLeft] = i;
//                 }
//             } else {
//                 if (nLeft > 0) {
//                     left.erase(nLeft);
//                     nLeft--;
//                     ans = max(ans, i - left[nLeft]);
//                 } else {
//                     left.clear();
//                     left[0] = i;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// solution using DP from https://leetcode.com/problems/longest-valid-parentheses/#/solutions
class Solution {
public:
    int longestValidParentheses(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int ans = 0;
        // store the length of the longest valid parentheses which ends in indices i
        vector<int> dp(s.size(), 0);
        for (int i = 1; i < s.length(); i++) {
            // left: current candidate to store '('
            int left = i - dp[i - 1] - 1;
            // if substring from left to i is a valid parentheses
            if (s[i] == ')' && left >= 0 && s[left] == '(') {
                // the current valid parentheses should be: dp[left-1] + dp[i-1] + 2
                dp[i] = dp[i - 1] + 2;
                if (left >= 1) {
                    dp[i] += dp[left - 1];
                }
                ans = max(dp[i], ans);
            }
        }
        return ans;
    }
};
// @lc code=end
