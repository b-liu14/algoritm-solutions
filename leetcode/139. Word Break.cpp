class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int l = (int)s.length(), n = (int)wordDict.size();
        vector<bool> dp(l, false);
        vector<vector<bool>> dp1(l, vector<bool>(l, false));
        for (int i = 0; i < l; i ++) {
            for (int j = 0; j < wordDict.size(); j ++) {
                if (s.substr(i, wordDict[j].length()) == wordDict[j]) {
                    dp1[i][i + wordDict[j].length() - 1] = true;
                }
            }
        }
        dp[0] = dp1[0][0];
        for (int i = 1; i < l; i ++) {
            dp[i] = dp1[0][i];
            for (int j = 0; j < i; j ++) {
                if (dp[j] && dp1[j+1][i]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[l-1];
    }
};
