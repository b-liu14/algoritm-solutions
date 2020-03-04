/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 *
 * https://leetcode.com/problems/reverse-pairs/description/
 *
 * algorithms
 * Hard (24.01%)
 * Likes:    709
 * Dislikes: 107
 * Total Accepted:    32.8K
 * Total Submissions: 134.6K
 * Testcase Example:  '[1,3,2,3,1]'
 *
 * Given an array nums, we call (i, j) an important reverse pair if i < j and
 * nums[i] > 2*nums[j].
 * 
 * You need to return the number of important reverse pairs in the given
 * array.
 * 
 * Example1:
 * 
 * Input: [1,3,2,3,1]
 * Output: 2
 * 
 * 
 * Example2:
 * 
 * Input: [2,4,3,5,1]
 * Output: 3
 * 
 * 
 * Note:
 * 
 * The length of the given array will not exceed 50,000.
 * All the numbers in the input array are in the range of 32-bit integer.
 * 
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
    // BIT solution
    // private:
    //     int low_bit(int index) {
    //         return index & (-index);
    //     }
    //     int query(const vector<int>& bit, int index) {
    //         int sum = 0;
    //         while (index > 0) {
    //             sum += bit[index];
    //             index -= low_bit(index);
    //         }
    //         return sum;
    //     }
    //     void update(vector<int>& bit, int index, int value) {
    //         while (index < bit.size()) {
    //             bit[index] += value;
    //             index += low_bit(index);
    //         }
    //     }

    // public:
    //     int reversePairs(vector<int>& nums) {
    //         vector<int> sorted = nums;
    //         sort(sorted.begin(), sorted.end());
    //         int cnt = 0;
    //         vector<int> bit(nums.size() + 1, 0);
    //         for (auto& n : nums) {
    //             auto index = lower_bound(sorted.begin(), sorted.end(), 2L * n + 1) - sorted.begin();
    //             cnt += query(bit, nums.size()) - query(bit, index);
    //             auto index_new = lower_bound(sorted.begin(), sorted.end(), n) - sorted.begin() + 1;
    //             update(bit, index_new, 1);
    //         }
    //         return cnt;
    //     }

    // merge sort solution.
public:
    int reversePairs(vector<int>& nums) {
        return solve(nums, 0, nums.size() - 1);
    }

    int solve(vector<int>& nums, int left, int right) {
        if (right <= left) {
            return 0;
        }

        int mid = (right + left) / 2;

        // recursive
        int cnt = solve(nums, left, mid) + solve(nums, mid + 1, right);

        // calcuate cross solution
        int i = left, j = mid + 1, k = 0;
        while (j <= right) {
            while (i <= mid && nums[i] <= nums[j] * 2L) {
                i++;
            }
            cnt += mid + 1 - i;
            j++;
        }

        // merge sort
        vector<int> tmp(right - left + 1, 0);
        i = left, j = mid + 1, k = 0;
        while (i <= mid || j <= right) {
            if (j > right || (i <= mid && nums[i] <= nums[j])) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        copy(tmp.begin(), tmp.end(), nums.begin() + left);

        return cnt;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums{2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 2147483647};
    cout << s.reversePairs(nums) << endl;

    return 0;
}