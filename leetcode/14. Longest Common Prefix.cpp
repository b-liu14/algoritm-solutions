class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        int minLen = INT_MAX;
        for (int i = 0; i < strs.size(); i++) {
            minLen = min(minLen, (int)strs[i].length());
        }
        for (int i = 0; i < minLen; i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0].substr(0, minLen);
    }
};
