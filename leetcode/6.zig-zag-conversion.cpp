/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (33.89%)
 * Likes:    1656
 * Dislikes: 4563
 * Total Accepted:    456.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */

// @lc code=start
class Solution {
public:
    string push_single(string s, string t, int N, int start) {
        while (start < s.length()) {
            t.push_back(s[start]);
            start += 2 * (N - 1);
        }
        return t;
    }
    string push_double(string s, string t, int N, int start) {
        int cur = start;
        while (cur < s.length()) {
            t.push_back(s[cur]);
            cur = cur + 2 * (N - 1) - 2 * start;
            if (cur < s.length()) {
                t.push_back(s[cur]);
                cur += 2 * start;
            } else {
                break;
            }
        }
        return t;
    }
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string t = "";

        t = push_single(s, "", numRows, 0);
        for (int i = 1; i <= numRows - 2; i++) {
            t = push_double(s, t, numRows, i);
        }
        t = push_single(s, t, numRows, numRows - 1);

        return t;
    }
};

// concise solution
string convert(string s, int nRows) {
    if (nRows <= 1)
        return s;
    string result = "";
    //the size of a cycle(period)
    int cycle = 2 * nRows - 2;
    for (int i = 0; i < nRows; ++i) {
        for (int j = i; j < s.length(); j = j + cycle) {
            result = result + s[j];
            int secondJ = (j - i) + cycle - i;
            if (i != 0 && i != nRows - 1 && secondJ < s.length())
                result = result + s[secondJ];
        }
    }
    return result;
}
// @lc code=end
