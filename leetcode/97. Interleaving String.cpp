class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) {
            return false;
        }
        vector<vector<int>> dp(s3.length()+1, vector<int>(s1.length()+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= s3.length(); i ++) {
            for (int j = 0; j <= i; j ++) {
                int k = i - j;
                if (j > s1.length() || k > s2.length()) {
                    continue;
                }
                dp[i][j] = (j > 0 && dp[i-1][j-1] && s1[j-1] == s3[i-1]) || (k > 0 && dp[i-1][j] && s2[k-1] == s3[i-1]);
            }
        }
        return dp.back().back();
    }
};
