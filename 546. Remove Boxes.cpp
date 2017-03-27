// stupid wrong solution using greeding
class Solution {
public:
    int dfs(vector<int>& boxes, int left, int right) {
        if (left >= right) {
            return 0;
        }
        if (right - left == 1) {
            return 1;
        }

        unordered_map<int, int> count;
        for (int i = left; i < right; i ++) {
            count[boxes[i]] ++;
        }
        int v = boxes[left];
        for (auto &c : count) {
            if (c.second > count[v]) {
                v = c.first;
            }
        }

        vector<int> tmp;
        int l = left;
        while (boxes[l] != v) {
            tmp.push_back(boxes[l]);
            l ++;
        }
        int r = right - 1;
        while (boxes[r] != v) {
            r --;
        }
        for (int i = r+1; i < right; i ++) {
            tmp.push_back(boxes[i]);
        }

        int ans = count[v] * count[v];
        int a1 = dfs(tmp, 0, (int)tmp.size());
        ans += a1;

        int i = l + 1;
        while(i < r) {
            while (l + 1 <= r && boxes[l+1] == boxes[l]) {
                i ++;
                l ++;
            };
            while (i < r && boxes[i] != boxes[l]) {
                i ++;
            }
            ans += dfs(boxes, l+1, i);
            l = i;
            i = l + 1;
        }

        return ans;
    }
    int removeBoxes(vector<int>& boxes) {
        return dfs(boxes, 0, (int)boxes.size());
    }
};

// elegant solution using dynamic programming
int dp[110][110][110];
class Solution {
    int f(vector<int> &a, int l, int r, int k) {
        if (l > r) {
            return 0;
        }
        int &ret = dp[l][r][k];
        if (ret >= 0) {
            return ret;
        }
        ret = f(a, l, r - 1, 0) + (k + 1) * (k + 1);
        for (int i = r - 1; i >= l; --i)
            if (a[i] == a[r])
                ret = max(ret, f(a, l, i, k + 1) + f(a, i + 1, r - 1, 0));
        return ret;
    }
public:
    int removeBoxes(vector<int>& a) {
        memset(dp, -1, sizeof dp);
        return f(a, 0, (int)a.size() - 1, 0);
    }
};
