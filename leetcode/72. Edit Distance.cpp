class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = (int)word1.length();
        int n2 = (int)word2.length();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        for (int i = 1; i <= n1; i ++) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= n2; i ++) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= n1; i ++) {
            for (int j = 1; j <= n2; j ++) {
                int tmp = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
                dp[i][j] = min(tmp, dp[i-1][j-1] + 1);
                // printf("i = %d, j = %d, tmp = %d, dp = %d\n", i, j, tmp, dp[i][j]);
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};
