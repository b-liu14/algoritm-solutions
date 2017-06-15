struct {
    bool operator()(string a, string b)
    {
        return a.length() > b.length();
    }
} customLess;

class Solution {
public:
    bool isSub(string a, string b) {
        int i = 0;
        for (int j = 0; j < b.length(); j ++) {
            while (i < a.length() && a[i] != b[j]) {
                i ++;
            }
            if (i >= a.length()) return false;
            i ++;
        }
        return true;
    }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), customLess);
        for (int i = 0; i < strs.size(); i ++) {
            int count = 0;
            for (int j = 0; j < strs.size(); j ++) {
                if (isSub(strs[j], strs[i])) count ++;
            }
            if (count == 1) return (int)strs[i].length();
        }
        return -1;
    }
};
