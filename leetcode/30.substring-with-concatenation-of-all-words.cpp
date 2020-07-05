/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (24.39%)
 * Likes:    845
 * Dislikes: 1229
 * Total Accepted:    175.2K
 * Total Submissions: 694.5K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * Output: []
 * 
 * 
 */

// O(N^2) brute force
// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         unordered_map<string, int> counts;

//         for (auto w : words) {
//             counts[w]++;
//         }
//         int n = (int)words.size();
//         int l = n ? (int)words[0].size() : 0;
//         int slen = (int)s.length();
//         vector<int> ans;
//         for (int i = 0; i <= slen - n * l; i++) {
//             unordered_map<string, int> seen;
//             int j = 0;
//             while (j < n) {
//                 int index = i + j * l;
//                 string word = s.substr(index, l);
//                 if (counts.count(word) == 0 || seen[word] >= counts[word]) {
//                     break;
//                 } else {
//                     seen[word]++;
//                 }
//                 j++;
//             }
//             if (j == n) {
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };

// @lc code=start
// O(N)
// sliding window scan
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        if (words.size() == 0) {
            return ans;
        }

        int l = (int)words[0].size();  // length of each word

        unordered_map<string, int> count;
        for (auto w : words) {
            count[w]++;
        }

        // for each start point, scan like sliding window
        for (int j = 0; j < l; j++) {
            unordered_map<string, int> seen;
            // start point of current concatenation
            int left = j;
            for (int i = j; i < (int)s.length(); i += l) {
                // scan next word
                string word = s.substr(i, l);

                // if word not found in words, update left to the next start point
                if (!count[word]) {
                    left = i + l;
                    seen.clear();
                } else {
                    // if this word has been seen more than count[word],
                    // move left to the first occuriency of this word in range (left, i)
                    if (seen[word] >= count[word]) {
                        while (s.substr(left, l) != word) {
                            seen[s.substr(left, l)]--;
                            left += l;
                        }
                        seen[s.substr(left, l)]--;
                        left += l;
                    }

                    seen[word]++;

                    // if the length of the current combination equals the length of all the words
                    // then left is a valid combination
                    // push back to the ans and move to the next start point
                    if (i + l - left == words.size() * l) {
                        ans.push_back(left);
                        seen[s.substr(left, l)]--;
                        left += l;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
