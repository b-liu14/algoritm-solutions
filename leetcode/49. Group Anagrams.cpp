class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> map;
        for (auto str: strs) {
            string s = str;
            sort(s.begin(), s.end());
            if (map.count(s)) {
                ans[map[s]].push_back(str);
            }
            else {
                map[s] = ans.size();
                vector<string> cur(1, str);
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
