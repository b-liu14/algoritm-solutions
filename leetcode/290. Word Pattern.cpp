class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> v;
        int begin = 0;
        for (int i = 0; i <= str.length(); i ++) {
            if (i == str.length() || str[i] == ' ') {
                v.push_back(str.substr(begin, i - begin));
                begin = i+1;
            }
        }
        if (pattern.length() != v.size()) {
            return false;
        }
        for (int i = 0; i < pattern.length(); i ++) {
            for (int j = i+1; j < pattern.length(); j ++) {
                // cout << i << j << (pattern[i] == pattern[j]) << (v[i] == v[j]) << endl;
                if ((pattern[i] == pattern[j]) != (v[i] == v[j])) {
                    return false;
                }
            }
        }
        return true;
    }
};
