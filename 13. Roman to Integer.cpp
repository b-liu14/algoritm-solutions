class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> lookup = {{'I', 1},{'V', 5},{'X', 10},
            {'L', 50},{'C', 100},{'D', 500},{'M', 1000}};

        int ans = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (i+1 < s.length() && lookup[s[i]] < lookup[s[i+1]]) {
                ans -= lookup[s[i]];
                ans += lookup[s[i+1]];
                i ++;
            }
            else {
                ans += lookup[s[i]];
            }
        }
        return ans;
    }
};
