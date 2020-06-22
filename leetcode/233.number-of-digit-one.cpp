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
        long long interval = 10, size = 1;
        int sum = 0;
        while (n >= size) {
            int n1 = n - size + 1;
            long long n2 = n1 + interval - size;
            sum += (n2 / interval) * size;
            int tmp = n1 % interval;
            if (tmp < size) {
                sum += tmp;
            }
            interval *= 10;
            size *= 10;
        }
        return sum;
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.countDigitOne(2147483647) << endl;
}