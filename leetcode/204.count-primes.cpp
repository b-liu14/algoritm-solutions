/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (30.15%)
 * Likes:    2211
 * Dislikes: 638
 * Total Accepted:    380.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '10'
 *
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * 
 * 
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 * 
 * 
 */

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        vector<bool> is_prime(n - 2, true);

        int cnt = 1;
        for (int i = 3; i < n; i += 2) {
            if (is_prime[i - 2]) {
                for (int j = i; j < ceil(float(n) / i); j++) {
                    is_prime[j * i - 2] = false;
                }
                cnt++;
            }
        }

        return cnt;
    }
};
// @lc code=end

int main() {
    Solution s;
    for (int i = 1; i <= 10; i++) {
        cout << i << " " << s.countPrimes(i) << endl;
    }

    return 0;
}