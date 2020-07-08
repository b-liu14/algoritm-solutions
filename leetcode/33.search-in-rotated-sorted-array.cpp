/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (33.38%)
 * Likes:    5013
 * Dislikes: 462
 * Total Accepted:    731K
 * Total Submissions: 2.1M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */

// @lc code=start
class Solution {
public:
    int find_mid(vector<int>& nums, int l, int r) {
        if (l == r)
            return r;
        int pos = (r + l) / 2;
        if (nums[pos] >= nums[0] && nums[pos + 1] < nums[0])
            return pos;
        else if (nums[pos] < nums[0])
            return find_mid(nums, l, pos - 1);
        else
            return find_mid(nums, pos + 1, r);
    };

    int binary_search(vector<int>& nums, int target, int l, int r) {
        if (l > r)
            return -1;

        int mid = (l + r) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            return binary_search(nums, target, mid + 1, r);
        else
            return binary_search(nums, target, l, mid - 1);
    }

    int search(vector<int>& nums, int target) {
        int mid = find_mid(nums, 0, nums.size() - 1);

        if (nums[0] > target) {
            if (mid < nums.size() - 1)
                return binary_search(nums, target, mid + 1, nums.size() - 1);
            else
                return -1;
        } else
            return binary_search(nums, target, 0, mid);
    };
};

// Clever solution from https://discuss.leetcode.com/topic/34491/clever-idea-making-it-simple/2
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            int num = (nums[mid] < nums[0]) == (target < nums[0])
                          ? nums[mid]
                          : target < nums[0] ? INT_MIN : INT_MAX;

            if (num < target) {
                lo = mid + 1;
            } else if (num > target) {
                hi = hi - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

// @lc code=end
