class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        vector<int> left(n, height[0]);
        for (int i = 1; i < height.size(); i ++) {
            left[i] = max(left[i-1], height[i]);
        }

        vector<int> right(n, height.back());
        for (int i = height.size() - 2; i >= 0; i --) {
            right[i] = max(right[i+1], height[i]);
        }

        int ans = 0;
        for (int i = 1; i < height.size(); i ++) {
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }
};
