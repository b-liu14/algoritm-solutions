/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.17%)
 * Likes:    1170
 * Dislikes: 5177
 * Total Accepted:    277K
 * Total Submissions: 1.7M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero, which means losing its
 * fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) =
 * -2.
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * Explanation: 10/3 = truncate(3.33333..) = 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * Explanation: 7/-3 = truncate(-2.33333..) = -2.
 * 
 * 
 * Note:
 * 
 * 
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 2^31 − 1 when the
 * division result overflows.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int getSign(int n) {
        if (n == 0)
            return 0;
        if (n > 0)
            return 1;
        return -1;
    }
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return INT_MAX;
        }
        int sign = getSign(dividend) * getSign(divisor);  // 0 -> zero, 1 -> positive, -1-> negetive.
        long long ded = abs((long long)dividend);
        long long dor = abs((long long)divisor);
        long long ans = 0;
        for (int nshift = 31; nshift >= 0; nshift--) {
            if (dor <= ((long long)1 << (31 - nshift))) {
                long long tmp = dor << nshift;
                if (ded >= tmp) {
                    ans += (long long)1 << nshift;
                    ded = ded - tmp;
                }
            }
        }
        if (sign == 1) {
            return ans > INT_MAX ? INT_MAX : (int)ans;
        } else {
            return (int)-ans;
        }
    }
};
// @lc code=end
