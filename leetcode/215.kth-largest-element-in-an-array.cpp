/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (50.91%)
 * Likes:    3025
 * Dislikes: 214
 * Total Accepted:    535.2K
 * Total Submissions: 1M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Find the kth largest element in an unsorted array. Note that it is the kth
 * largest element in the sorted order, not the kth distinct element.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,1,5,6,4] and k = 2
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,3,1,2,4,5,5,6] and k = 4
 * Output: 4
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void swap(int& x, int& y) {
        int tmp = x;
        x = y;
        y = tmp;
    }
    int partition(vector<int>& nums, int l, int r) {
        int& pivot = nums[r - 1];
        int idx = l;
        for (int i = l; i < r - 1; i++) {
            if (nums[i] < pivot) {
                swap(nums[i], nums[idx]);
                idx++;
            }
        }
        swap(nums[idx], pivot);
        return idx;
    }
    int findKthSmallest(vector<int>& nums, int l, int r, int k) {
        int idx = partition(nums, l, r);
        if (idx == k) {
            return nums[idx];
        } else if (idx < k) {
            return findKthSmallest(nums, idx + 1, r, k);
        } else {
            return findKthSmallest(nums, l, idx, k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        return findKthSmallest(nums, 0, nums.size(), nums.size() - k);
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums{3, 2, 1, 5, 6, 4};
    cout << s.findKthLargest(nums, 2) << endl;

    return 0;
}