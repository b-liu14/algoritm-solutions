/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (33.07%)
 * Likes:    1382
 * Dislikes: 3137
 * Total Accepted:    671.9K
 * Total Submissions: 1.8M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * s consists only of printable ASCII characters.
 * 
 * 
 */

#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        for (auto c : s) {
            if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) {
                s1.push_back(c);
            } else if (c >= 'A' && c <= 'Z') {
                s1.push_back(c - 'A' + 'a');
            }
        }
        int n = s1.size();
        for (int i = 0; i < n / 2; i++) {
            if (s1[i] != s1[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.isPalindrome("A man, a plan, a canal: Panama");

    return 0;
}