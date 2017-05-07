// dp
class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int N = (int)flights.size();
        int K = N ? (int)days[0].size() : 0;
        vector<vector<int>> dp(N, vector<int>(K, 0));
        unordered_set<int> srcs;
        srcs.insert(0);
        for (int d = 0; d < K; d ++) {
            unordered_set<int> srcs_tmp = srcs;
            for (auto i: srcs) {
                for (int j = 0; j < N; j ++) {
                    if (i == j || flights[i][j]) {
                        // dp[d][j]
                        dp[j][d] = max(dp[j][d], (d > 0 ? dp[i][d-1] : 0) + days[j][d]);
                        srcs_tmp.insert(j);
                    }
                }
            }
            srcs = srcs_tmp;
        }
        int ans = 0;
        for (int i = 0; i < N; i ++) {
            ans = max(ans, dp[i][K-1]);
        }
        return ans;
    }
};
