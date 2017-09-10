class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int n = 1, ans = 1;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] > nums[i-1]) {
                n ++;
            }
            else {
                ans = max(ans, n);
                n = 1;
            }
        }
        return max(ans, n);
    }
};
