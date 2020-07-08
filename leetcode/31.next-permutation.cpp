/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (31.36%)
 * Likes:    3381
 * Dislikes: 1221
 * Total Accepted:    370K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int left = (int)nums.size() - 1;
        while (left > 0 && nums[left - 1] >= nums[left]) {
            left--;
        }
        if (left > 0) {
            auto iter = upper_bound(nums.rbegin(), nums.rbegin() + nums.size() - left, nums[left - 1]);
            swap(nums[left - 1], *iter);
        }

        // swap the tail
        int right = (int)nums.size() - 1;
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }
};
// @lc code=end

int main() {
    vector<int> nums{4, 3, 2, 1};
    Solution s;
    s.nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}