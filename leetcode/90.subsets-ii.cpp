/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (44.35%)
 * Likes:    1170
 * Dislikes: 56
 * Total Accepted:    234.4K
 * Total Submissions: 528.4K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */

#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}, };
        int k = 0; 
        for (int i = 0; i < nums.size(); i ++) {
            int n = res.size();
            for (int j = k; j < n; j ++) {
                auto tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
            if (i < nums.size() - 1 && nums[i+1] == nums[i]) {
                k = n;
            }
            else {
                k = 0;
            }
        }
        return res;
    }
};
// @lc code=end

