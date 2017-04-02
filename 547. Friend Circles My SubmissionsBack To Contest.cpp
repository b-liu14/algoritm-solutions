
class Solution {
public:
    void dfs(vector<vector<int>>& M, vector<bool>& v, int i) {
        v[i] = true;
        for (int j = 0; j < M.size(); j ++) {
            if (!v[j] && M[i][j] == 1) {
                dfs(M, v, j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        vector<bool> v(N, false);
        int ans = 0;
        for (int i = 0; i < M.size(); i ++) {
            if (v[i]) continue;
            ans ++;
            dfs(M, v, i);
        }
        return ans;
    }
};
