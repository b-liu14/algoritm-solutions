/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (26.91%)
 * Likes:    1804
 * Dislikes: 215
 * Total Accepted:    177.6K
 * Total Submissions: 627.8K
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non negative integers, arrange them such that they form the
 * largest number.
 * 
 * Example 1:
 * 
 * 
 * Input: [10,2]
 * Output: "210"
 * 
 * Example 2:
 * 
 * 
 * Input: [3,30,34,5,9]
 * Output: "9534330"
 * 
 * 
 * Note: The result may be very large, so you need to return a string instead
 * of an integer.
 * 
 */

#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

// @lc code=start

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // convert to string and sort numbers
        vector<string> snums(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            snums[i] = to_string(nums[i]);
        }
        sort(snums.begin(), snums.end(), [](string& a, string& b) {
            return a + b > b + a;
        });

        // special case when all numbers are 0
        if (snums[0] == "0") {
            return "0";
        }

        // concat to get result
        string result = "";
        for (auto& n : snums) {
            result += n;
        }

        return result;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {3, 30, 34, 5, 9};
    Solution s;
    cout << s.largestNumber(nums) << endl;

    return 0;
}