class Solution {
public:
    string recur(int n, vector<string> strs) {
        if (n == 1) {
            return strs[0];
        }
        for (int i = 0; i < n/2; i ++) {
            strs[i] = "(" + strs[i] + "," + strs[n-i-1] + ")";
        }
        return recur(n/2, strs);
    }
    string findContestMatch(int n) {
        vector<string> strs(n);
        for (int i = 0; i < n; i ++) {
            strs[i] = to_string(i+1);
        }
        return recur(n, strs);
    }
};
