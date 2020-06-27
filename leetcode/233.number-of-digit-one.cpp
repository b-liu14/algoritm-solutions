/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 *
 * https://leetcode.com/problems/number-of-digit-one/description/
 *
 * algorithms
 * Hard (30.78%)
 * Likes:    266
 * Dislikes: 601
 * Total Accepted:    47.8K
 * Total Submissions: 153.2K
 * Testcase Example:  '13'
 *
 * Given an integer n, count the total number of digit 1 appearing in all
 * non-negative integers less than or equal to n.
 * 
 * Example:
 * 
 * 
 * Input: 13
 * Output: 6 
 * Explanation: Digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 * 
 * 
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int countDigitOne(int n) {
        int sum = 0;
        // 遍历每一位
        for (long long size = 1; size <= n; size *= 10) {
            int prefix = n / size, suffix = n % size;
            // 若当前位的值大于1，则1共出现 (prefix / 10 + 1) * size 次
            // 若当前位的值等于1，则1共出现 (prefix / 10) * size + suffix + 1 次
            // 若当前位的值等于0，则1共出现 (prefix / 10) * size 次
            sum += (prefix + 8) / 10 * size + (prefix % 10 == 1) * (suffix + 1);
        }
        return sum;
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.countDigitOne(2147483647) << endl;
}