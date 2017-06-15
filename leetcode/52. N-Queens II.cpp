typedef unordered_map<int, bool> UMAP;
class Solution {
public:
    int ans;
    void dfs(int n, int curRow, UMAP& column, UMAP& sum, UMAP& diff) {
        if (curRow == n) {
            ans ++;
            return;
        }
        for (int i = 0; i < n; i ++) {
            if (column[i] || sum[i+curRow] || diff[i-curRow]) continue;
            column[i] = true;
            sum[i+curRow] = true;
            diff[i-curRow] = true;
            dfs(n, curRow+1, column, sum, diff);
            column[i] = false;
            sum[i+curRow] = false;
            diff[i-curRow] = false;
        }
    }

    int totalNQueens(int n) {
        UMAP column;
        UMAP sum;
        UMAP diff;
        ans = 0;
        dfs(n, 0, column, sum, diff);
        return ans;
    }
};
