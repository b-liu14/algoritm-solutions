/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 *
 * https://leetcode.com/problems/count-of-range-sum/description/
 *
 * algorithms
 * Hard (33.95%)
 * Likes:    589
 * Dislikes: 75
 * Total Accepted:    38.7K
 * Total Submissions: 112.6K
 * Testcase Example:  '[-2,5,-1]\n-2\n2'
 *
 * Given an integer array nums, return the number of range sums that lie in
 * [lower, upper] inclusive.
 * Range sum S(i, j) is defined as the sum of the elements in nums between
 * indices i and j (i ≤ j), inclusive.
 * 
 * Note:
 * A naive algorithm of O(n^2) is trivial. You MUST do better than that.
 * 
 * Example:
 * 
 * 
 * Input: nums = [-2,5,-1], lower = -2, upper = 2,
 * Output: 3 
 * Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective
 * sums are: -2, -1, 2.
 * 
 */

#include <iostream>
#include <set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> s{0};
        long long sum = 0, cnt = 0;
        for (auto& num : nums) {
            sum += num;
            cnt += distance(s.lower_bound(sum - upper), s.upper_bound(sum - lower));
            s.insert(sum);
        }
        return cnt;
    }
};

// @lc code=end

int main() {
    Solution s;
    vector<int> nums{2147483647, -2147483648, -1, 0};
    cout << s.countRangeSum(nums, -1, 0) << endl;
    return 0;
}
