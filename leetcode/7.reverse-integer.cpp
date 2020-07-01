/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.54%)
 * Likes:    3367
 * Dislikes: 5313
 * Total Accepted:    1.1M
 * Total Submissions: 4.3M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        bool neg = (x < 0);
        x = abs(x);
        int ans = 0;
        while (x > 0) {
            int c = x % 10;
            if (ans > (INT_MAX - c) / 10) {
                return 0;
            }
            ans = ans * 10 + c;
            x /= 10;
        }

        return neg ? -ans : ans;
    }
};

// short solution using long long
class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while (x != 0) {
            ans = ans * 10 + x % 10;
            x /= 10;
            if (ans > INT_MAX || ans < INT_MIN) {
                return 0;
            }
        }
        return (int)ans;
    }
};
// @lc code=end
