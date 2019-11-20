/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, k = nums.size() - 1;
        // only for spped up. Can be commented
        while (i < nums.size() && nums[i] == 0) {
            i ++;
        }
        while (k >= 0 && nums[k] == 2) {
            k --;
        }
        // main loop
        int j = i;
        while (j <= k) {
            if (nums[j] == 0) {
                swap(nums[i], nums[j]);
                i ++; 
                j ++;
            }
            else if (nums[j] == 1) {
                j ++;
            }
            else {
                swap(nums[j], nums[k]);
                k --;
            }
        }
    }
};
// @lc code=end

