class Solution {
public:
    vector<int> count(string s) {
        vector<int> v(26, 0);
        for (int i = 0; i < s.length(); i ++) {
            v[s[i] - 'a'] ++;
        }
        return v;
    }
    bool checkInclusion(string s1, string s2) {
        int l1 = (int)s1.length();
        auto v1 = count(s1);
        auto v2 = count(s2.substr(0, l1));
        if (v1 == v2) {
            return true;
        }
        for (int i = 1; i <= (int)s2.length() - (int)s1.length(); i ++) {
            v2[s2[i-1]-'a'] --;
            v2[s2[i+l1-1]-'a'] ++;
            if (v1 == v2) {a
                return true;
            }
        }
        return false;
    }
};
