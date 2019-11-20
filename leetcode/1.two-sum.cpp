/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
// two way hash table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i ++) {
            if (umap.find(nums[i]) != umap.end()) {
                return vector<int>({umap[nums[i]], i});
            }
            else {
                umap[target - nums[i]] = i;
            }
        }
        return vector<int>();
    }
};
// @lc code=end
