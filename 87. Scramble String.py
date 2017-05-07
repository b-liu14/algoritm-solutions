# dfs
from collections import Counter
import re

class Solution(object):
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if s1 == s2:
            return True
        if Counter(s1) != Counter(s2):
            return False
        for i in range(1, len(s1)):
            if self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:]):
                return True
            if self.isScramble(s1[:i], s2[-i:]) and self.isScramble(s1[i:], s2[:-i]):
                return True
        return False

# dp of C++
class Solution {
public:
    bool _isScramble(int i, int j, int k, vector<vector<vector<bool>>>& dp) {
        for (int l1 = 1; l1 < k; l1 ++) {
            if ((dp[i][j][l1] && dp[i+l1][j+l1][k-l1]) ||
                (dp[i][j+l1][k-l1] && dp[i+k-l1][j][l1])) {
                return true;
            }
        }
        return false;
    }
    bool isScramble(string s1, string s2) {
        int l = (int)s1.length();
        auto dp = vector<vector<vector<bool>>>(l, vector<vector<bool>>(l, vector<bool>(l+1, false)));
        for (int k = 0; k < l+1; k ++) {
            for (int i = 0; i < l; i ++) {
                for (int j = 0; j < l; j ++) {
                    if (i + k > l || j + k > l) {
                        continue;
                    }
                    if (s1.substr(i, k) == s2.substr(j, k)) {
                        dp[i][j][k] = true;
                        continue;
                    }
                    dp[i][j][k] = _isScramble(i, j, k, dp);
                }
            }
        }
        return dp[0][0][l];
    }
};
