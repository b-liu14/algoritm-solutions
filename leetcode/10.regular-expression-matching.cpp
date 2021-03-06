/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (25.93%)
 * Likes:    3749
 * Dislikes: 647
 * Total Accepted:    399.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore,
 * it matches "aab".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 * 
 * 
 */

// long solution using NFA
class State {
public:
    State* next;
    bool isTerminal;
    const static char dot = '.';
    const static char star = '*';
    const static char epsilon = '-';
    const static char notoken = ' ';

    char token2next;
    char token2myself;
    State(State* _next = nullptr, int _token2next = notoken, int _token2myself = notoken) {
        next = _next;
        token2next = _token2next;
        token2myself = _token2myself;
        isTerminal = false;
    };
};

class Solution {
public:
    State* buildNFA(string p) {
        State* start = new State();
        State* cur = start;
        for (int i = 0; i < p.length(); i++) {
            if (p[i] == State().star)
                continue;
            cur->next = new State();
            char c = p[i];
            if (p[i + 1] == State().star) {
                cur->token2next = State().epsilon;
                cur = cur->next;
                cur->token2myself = c;
                i += 1;
            } else {
                cur->token2next = c;
                cur = cur->next;
                cur->token2myself = State().notoken;
            }
        }
        cur->isTerminal = true;
        return start;
    }
    bool solve(string s, int index, State* state) {
        if (index >= s.length()) {
            if (!state->isTerminal && state->token2next == State().epsilon) {
                return solve(s, index, state->next);
            } else {
                return state->isTerminal;
            }
        }
        // myself?
        if (state->token2myself == state->dot || state->token2myself == s[index]) {
            if (solve(s, index + 1, state)) {
                return true;
            }
        }
        // next?
        if (state->token2next == state->epsilon) {
            if (solve(s, index, state->next)) {
                return true;
            }
        } else {
            if (state->token2next == state->dot || state->token2next == s[index]) {
                if (solve(s, index + 1, state->next)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isMatch(string s, string p) {
        State* start = buildNFA(p);
        return solve(s, 0, start);
    }
};

// back tracking
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }

        if ('*' == p[1]) {
            // x* matches empty string or at least one character: x* -> xx*
            // *s is to ensure s is non-empty
            if (isMatch(s, p.substr(2)))
                return true;
            if (!s.empty()) {
                if (s[0] == p[0] || p[0] == '.')
                    return isMatch(s.substr(1), p);
            }
        } else if (!s.empty()) {
            if (s[0] == p[0] || '.' == p[0])
                return isMatch(s.substr(1), p.substr(1));
        }
        return false;
    }
};

// @lc code=start
// dynamic programming
class Solution {
public:
    inline bool isMatch(char s, char p) {
        return p == '?' || s == p;
    }

    bool isMatch(string s, string p) {
        int sl = (int)s.length();
        int pl = (int)p.length();
        // vector is more convenient while array is more quick.
        // vector<vector<bool>> dp(sl+1, vector<bool>(pl+1, false));
        bool dp[sl + 1][pl + 1];
        for (int i = 1; i <= sl; i++) {
            dp[i][0] = false;
        }

        dp[0][0] = true;
        for (int i = 0; i <= sl; i++) {
            for (int j = 1; j <= pl; j++) {
                if (p[j - 1] != '*') {
                    // exactly matching?
                    dp[i][j] = i > 0 && isMatch(s[i - 1], p[j - 1]) && dp[i - 1][j - 1];
                } else {
                    // match zero time?
                    bool tmp1 = j >= 1 && dp[i][j - 1];
                    // match at least one time?
                    bool tmp2 = i > 0 && isMatch(s[i - 1], p[j - 1]) && dp[i - 1][j];
                    dp[i][j] = tmp1 || tmp2;
                }
            }
        }
        return dp[sl][pl];
    }
};
// @lc code=end
