class Solution {
public:
    vector<int> count(string s) {
        vector<int> v(26, 0);
        for (int i = 0; i < s.length(); i ++) {
            v[s[i] - 'a'] ++;
        }
        return v;
    }
    bool equal(vector<int>& v1, string s2) {
        auto v2 = count(s2);
        return (v1 == v2);
    }
    bool checkInclusion(string s1, string s2) {
        auto v1 = count(s1);
        for (int i = 0; i <= (int)s2.length() - (int)s1.length(); i ++) {
            if (equal(v1, s2.substr(i, s1.length()))) {
                return true;
            }
        }
        return false;
    }
};
