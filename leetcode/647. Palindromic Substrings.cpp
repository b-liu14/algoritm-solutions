class Solution {
public:
    int countSubstrings(string s) {
        int n = (int)s.size();
        vector<vector<bool>> is(n, vector<bool>(n, false));
        for (int i = 0; i < n; i ++) {
            is[i][i] = true;
        }
        for (int l = 1; l < n; l ++) {
            for (int i = 0; i < n; i ++) {
                int j = i + l;
                if (j >= n) continue;
                is[i][j] = (s[i] == s[j] && (j == i + 1 || is[i+1][j-1]));
            }
        }
        int ret = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = i; j < n; j ++) {
                if (is[i][j]) {
                    ret ++;
                }
            }
        }
        return ret;
    }
};
