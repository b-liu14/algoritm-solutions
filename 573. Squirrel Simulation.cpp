class Solution {
public:
    int dist(vector<int>& p1, vector<int>& p2) {
        int ans = 0;
        for (int i = 0; i < p1.size(); i ++) {
            ans += abs(p1[i] - p2[i]);
        }
        return ans;
    }
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        long long allDist = 0;
        for (int i = 0; i < nuts.size(); i ++) {
            allDist += 2 * dist(tree, nuts[i]);
        }
        long long ans = INT_MAX;
        for (int i = 0; i < nuts.size(); i ++) {
            auto cur = allDist + dist(squirrel, nuts[i]) - dist(nuts[i], tree);
            ans = min(ans, cur);
        }
        return (int)ans;
    }
};
