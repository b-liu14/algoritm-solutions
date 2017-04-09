class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> M;
        int m = wall.size();
        for (auto line: wall) {
            int x = 0;
            for (auto w: line) {
                M[x] ++;
                x += w;
            }
        }
        int ans = m;
        for (auto v: M) {
            if (v.first != 0) {
                ans = min(ans, m - v.second);
            }
        }
        return ans;
    }
};
