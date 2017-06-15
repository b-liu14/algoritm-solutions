// O(N^4) time limit exceeded
class Solution {
public:
    bool allOne(vector<vector<int>>& count, int l, int u, int r, int b) {
        return 0 == (getCount(count, b, r) + getCount(count, u-1, l-1)
                     - getCount(count, b, l-1) - getCount(count, u-1, r));
    }
    int getCount(vector<vector<int>>& count, int i, int j) {
        if (i < 0 || j < 0) {
            return 0;
        }
        return count[i][j];
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        int ans = 0;
        vector<vector<int>> count(m, vector<int>(n, 0));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                count[i][j] = (matrix[i][j] == '0')
                + getCount(count, i-1, j) + getCount(count, i, j-1)
                - getCount(count, i-1, j-1);
            }
        }
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                for (int i1 = i; i1 < m; i1 ++) {
                    for (int j1 = j; j1 < n; j1 ++) {
                        if (allOne(count, j, i, j1, i1)) {
                            ans = max(ans, (j1-j+1)*(i1-i+1));
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// O(N^3)
class Solution {
public:
    bool allOne(vector<vector<int>>& count, int c, int u, int b) {
        // return 0 == (getCount(count, b, c) - getCount(count, u-1, c));
        return 0 == (getCount(count, b, c) + getCount(count, u-1, c-1)
                     - getCount(count, b, c-1) - getCount(count, u-1, c));
    }

    int getCount(vector<vector<int>>& count, int i, int j) {
        if (i < 0 || j < 0) {
            return 0;
        }
        return count[i][j];
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        int ans = 0;
        vector<vector<int>> count(m, vector<int>(n, 0));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                count[i][j] = (matrix[i][j] == '0')
                + getCount(count, i-1, j) + getCount(count, i, j-1)
                - getCount(count, i-1, j-1);
            }
        }
        for (int i = 0; i < m; i ++) {
            for (int j = i; j < m; j ++) {
                int left = -1;
                for (int c = 0; c < n; c ++) {
                    if (allOne(count, c, i, j)) {
                        ans = max(ans, (j-i+1) * (c - left));
                    }
                    else {
                        left = c;
                    }
                }
            }
        }
        return ans;
    }
};
