typedef unordered_map<int, bool> UMAP;
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> cur;
    void dfs(int n, int curRow, UMAP& column, UMAP& sum, UMAP& diff) {
        if (curRow == n) {
            ans.push_back(cur);
        }
        for (int i = 0; i < n; i ++) {
            if (column[i] || sum[i+curRow] || diff[i-curRow]) continue;
            string str(n, '.');
            str[i] = 'Q';
            cur.push_back(str);
            column[i] = true;
            sum[i+curRow] = true;
            diff[i-curRow] = true;
            dfs(n, curRow+1, column, sum, diff);
            cur.pop_back();
            column[i] = false;
            sum[i+curRow] = false;
            diff[i-curRow] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        UMAP column;
        UMAP sum;
        UMAP diff;
        dfs(n, 0, column, sum, diff);
        return ans;
    }
};
