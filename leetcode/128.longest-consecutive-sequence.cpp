/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (44.93%)
 * Likes:    3502
 * Dislikes: 184
 * Total Accepted:    309.1K
 * Total Submissions: 686.4K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * 
 * 
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 */

#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
   public:
    int longestConsecutive(vector<int> &nums) {
        typedef pair<int, int> PII;
        typedef list<PII> LPII;
        LPII ranges;  // store range: [low, high]
        // store the iterator of low and high in the list
        // for location in O(1) time complexity
        unordered_map<int, LPII::iterator> low_map, high_map;
        // whether we have used the number
        unordered_map<int, int> cnt;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            // we have used the number, continue
            if (cnt.find(nums[i]) != cnt.end()) {
                continue;
            }
            // otherwise, mark as used
            cnt[nums[i]]++;

            int low = nums[i], high = nums[i];
            // find upper range
            if (low_map.find(nums[i] + 1) != low_map.end()) {
                high = low_map[nums[i] + 1]->second;
                ranges.erase(low_map[nums[i] + 1]);
                low_map.erase(nums[i] + 1);
            }
            // find lower range
            if (high_map.find(nums[i] - 1) != high_map.end()) {
                low = high_map[nums[i] - 1]->first;
                ranges.erase(high_map[nums[i] - 1]);
                high_map.erase(nums[i] - 1);
            }
            // update answer
            ans = max(ans, high - low + 1);
            // update new range and maps
            ranges.emplace_front(low, high);
            low_map[low] = ranges.begin();
            high_map[high] = ranges.begin();
        }
        return ans;
    }
};
// @lc code=end

int main() {
    vector<int> nums = {-7, -1, 3, -9, -4, 7, -3, 2, 4, 9, 4, -9, 8, -7, 5, -1, -7};
    Solution s;
    cout << s.longestConsecutive(nums) << endl;

    return 0;
}