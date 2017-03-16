class Solution {
public:
    const vector<string> dict = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void DFS(string digits, int depth, vector<string>& ans, string cur) {
        if (depth >= digits.size()) {
            if (depth) {
                ans.push_back(cur);
            }
            return;
        }
        string str = dict[digits[depth] - '0'];
        for (int j = 0; j < str.length(); j ++) {
            cur.push_back(str[j]);
            DFS(digits, depth+1, ans, cur);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        DFS(digits, 0, ans, "");
        return ans;
    }
};
