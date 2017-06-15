class Solution {
public:
    void add(vector<string>& res, string cur, int nLeft, int nLess) {
        if (nLeft == 0 && nLess == 0) {
            res.push_back(cur);
            return;
        }
        if (nLeft > 0) {
            add(res, cur+"(", nLeft-1, nLess+1);
        }
        if (nLess > 0) {
            add(res, cur+")", nLeft, nLess-1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        add(res, "", n, 0);
        return res;
    }
};
