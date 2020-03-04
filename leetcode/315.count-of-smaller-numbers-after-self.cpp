/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 *
 * https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (39.98%)
 * Likes:    1788
 * Dislikes: 69
 * Total Accepted:    109.2K
 * Total Submissions: 268.4K
 * Testcase Example:  '[5,2,6,1]'
 *
 * You are given an integer array nums and you have to return a new counts
 * array. The counts array has the property where counts[i] is the number of
 * smaller elements to the right of nums[i].
 * 
 * Example:
 * 
 * 
 * Input: [5,2,6,1]
 * Output: [2,1,1,0] 
 * Explanation:
 * To the right of 5 there are 2 smaller elements (2 and 1).
 * To the right of 2 there is only 1 smaller element (1).
 * To the right of 6 there is 1 smaller element (1).
 * To the right of 1 there is 0 smaller element.
 * 
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
    int low_bit(int x) {
        return x & -x;
    }
    int query(vector<int>& BIT, int index) {
        int sum = 0;
        while (index > 0) {
            sum += BIT[index];
            index -= low_bit(index);
        }
        return sum;
    }
    void update(vector<int>& BIT, int index, int val) {
        while (index < BIT.size()) {
            BIT[index] += val;
            index += low_bit(index);
        }
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> BIT(nums.size(), 0);
        vector<int> ans(nums.size(), 0);
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        for (int i = nums.size() - 1; i >= 0; i--) {
            int index = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin();
            ans[i] = query(BIT, index);
            int index_larger = lower_bound(sorted.begin(), sorted.end(), nums[i] + 1) - sorted.begin();
            update(BIT, index_larger, 1);
        }
        return ans;
    }
};
// @lc code=end
