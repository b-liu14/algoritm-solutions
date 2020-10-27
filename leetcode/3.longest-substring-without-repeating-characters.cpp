/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (29.14%)
 * Likes:    8249
 * Dislikes: 500
 * Total Accepted:    1.4M
 * Total Submissions: 4.7M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> char2idx(256, -1);
        int max_length = 0, start = -1;
        for (int i = 0; i < s.length(); i++) {
            start = max(start, char2idx[s[i]]);
            max_length = max(max_length, i - start);
            char2idx[s[i]] = i;
        }
        return max_length;
    }
};
// @lc code=end
