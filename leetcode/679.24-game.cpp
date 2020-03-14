/*
 * @lc app=leetcode id=679 lang=cpp
 *
 * [679] 24 Game
 *
 * https://leetcode.com/problems/24-game/description/
 *
 * algorithms
 * Hard (44.29%)
 * Likes:    582
 * Dislikes: 119
 * Total Accepted:    32.3K
 * Total Submissions: 71.6K
 * Testcase Example:  '[4,1,8,7]'
 *
 * 
 * You have 4 cards each containing a number from 1 to 9.  You need to judge
 * whether they could operated through *, /, +, -, (, ) to get the value of
 * 24.
 * 
 * 
 * Example 1:
 * 
 * Input: [4, 1, 8, 7]
 * Output: True
 * Explanation: (8-4) * (7-1) = 24
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 2, 1, 2]
 * Output: False
 * 
 * 
 * 
 * Note:
 * 
 * The division operator / represents real division, not integer division.  For
 * example, 4 / (1 - 2/3) = 12.
 * Every operation done is between two numbers.  In particular, we cannot use -
 * as a unary operator.  For example, with [1, 1, 1, 1] as input, the
 * expression -1 - 1 - 1 - 1 is not allowed.
 * You cannot concatenate numbers together.  For example, if the input is [1,
 * 2, 1, 2], we cannot write this as 12 + 12.
 * 
 * 
 * 
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<double> nums_double;
        for (auto n : nums) {
            nums_double.push_back(n);
        }
        return judgePoint24(nums_double);
    }
    bool close(double x, double y) {
        return abs(x - y) < 1e-8;
    }
    bool judgePoint24(vector<double>& nums) {
        if (nums.size() == 1) {
            return close(nums[0], 24);
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                vector<double> tmp;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j)
                        tmp.push_back(nums[k]);
                }
                vector<double> candidates = {
                    nums[i] + nums[j],
                    nums[i] - nums[j],
                    nums[j] - nums[i],
                    nums[i] * nums[j],
                };
                if (nums[i]) {
                    candidates.push_back(nums[j] / nums[i]);
                }
                if (nums[j]) {
                    candidates.push_back(nums[i] / nums[j]);
                }
                for (auto candidate : candidates) {
                    tmp.push_back(candidate);
                    if (judgePoint24(tmp)) {
                        return true;
                    }
                    tmp.pop_back();
                }
            }
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums{1, 2, 1, 2};
    cout << s.judgePoint24(nums) << endl;
    return 0;
}
