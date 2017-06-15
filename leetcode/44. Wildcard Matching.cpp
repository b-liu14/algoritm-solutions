// solution using dynamic programming(according to p10);
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
        bool dp[sl+1][pl+1];
        for (int i = 1; i <= sl; i ++) {
            dp[i][0] = false;
        }

        dp[0][0] = true;
        for (int i = 0; i <= sl; i ++) {
            for (int j = 1; j <= pl; j ++) {
                if (p[j-1] != '*') {
                    // exactly matching?
                    dp[i][j] = i > 0 && isMatch(s[i-1], p[j-1]) && dp[i-1][j-1];
                }
                else {
                    // match zero time?
                    bool tmp1 = dp[i][j-1];
                    // match at least one time?
                    bool tmp2 = i > 0 && dp[i-1][j];
                    dp[i][j] = tmp1 || tmp2;
                }
            }
        }
        return dp[sl][pl];
    }
};
