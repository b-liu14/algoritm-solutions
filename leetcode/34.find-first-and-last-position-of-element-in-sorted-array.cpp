/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (34.58%)
 * Likes:    3450
 * Dislikes: 147
 * Total Accepted:    502.9K
 * Total Submissions: 1.4M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * nums is a non decreasing array.
 * -10^9 <= target <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int getfBound(vector<int>& nums, int target, string type) {
        int lo = 0, hi = (int)nums.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;

            if (nums[mid] > target) {
                hi = mid;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                if (type == "left") {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
        }
        return lo;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        ans[0] = getfBound(nums, target, "left");
        ans[1] = getfBound(nums, target, "right") - 1;
        if (ans[0] > ans[1]) {
            ans[0] = -1;
            ans[1] = -1;
        }
        return ans;
    }
};
// @lc code=end
