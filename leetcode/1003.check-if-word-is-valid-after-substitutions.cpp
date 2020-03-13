/*
 * @lc app=leetcode id=1003 lang=cpp
 *
 * [1003] Check If Word Is Valid After Substitutions
 *
 * https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/description/
 *
 * algorithms
 * Medium (53.22%)
 * Likes:    138
 * Dislikes: 225
 * Total Accepted:    16.5K
 * Total Submissions: 30.5K
 * Testcase Example:  '"aabcbc"'
 *
 * We are given that the string "abc" is valid.
 * 
 * From any valid string V, we may split V into two pieces X and Y such that X
 * + Y (X concatenated with Y) is equal to V.  (X or Y may be empty.)  Then, X
 * + "abc" + Y is also valid.
 * 
 * If for example S = "abc", then examples of valid strings are: "abc",
 * "aabcbc", "abcabc", "abcabcababcc".  Examples of invalid strings are:
 * "abccba", "ab", "cababc", "bac".
 * 
 * Return true if and only if the given string S is valid.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "aabcbc"
 * Output: true
 * Explanation: 
 * We start with the valid string "abc".
 * Then we can insert another "abc" between "a" and "bc", resulting in "a" +
 * "abc" + "bc" which is "aabcbc".
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "abcabcababcc"
 * Output: true
 * Explanation: 
 * "abcabcabc" is valid after consecutive insertings of "abc".
 * Then we can insert "abc" before the last letter, resulting in "abcabcab" +
 * "abc" + "c" which is "abcabcababcc".
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "abccba"
 * Output: false
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "cababc"
 * Output: false
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= S.length <= 20000
 * S[i] is 'a', 'b', or 'c'
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isValid(string S) {
        // speed up
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // pruning
        if (S.size() % 3 != 0) {
            return false;
        }

        // solve the problem
        stack<char> s;
        for (auto c : S) {
            if (c == 'a') {
                s.push('a');
            } else if (c == 'b') {
                if (s.empty() || s.top() != 'a') {
                    return false;
                }
                s.pop();
                s.push('b');
            } else if (c == 'c') {
                if (s.empty() || s.top() != 'b') {
                    return false;
                }
                s.pop();
            } else {
                return false;
            }
        }
        return s.empty();
    }
};
// @lc code=end
