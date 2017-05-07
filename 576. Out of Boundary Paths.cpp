class Solution {
public:
    int mod = 1000000000 + 7;
    int get_dp(int i, int j, int k, vector<vector<vector<int>>>& dp) {
        if (i < 0 || j < 0 || i >= dp.size() || j >= dp[0].size()) {
            return 1;
        }
        if (k == 0) {
            return 0;
        }
        int& v = dp[i][j][k-1];
        if (v != -1) {
            return v;
        }
        v = (int)(((long long)get_dp(i-1, j, k-1, dp) + get_dp(i+1, j, k-1, dp)
             + get_dp(i, j-1, k-1, dp) + get_dp(i, j+1, k-1, dp)) % mod);
        return v;
    }


    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(N, -1)));
        return get_dp(i, j, N, dp);
    }
};
