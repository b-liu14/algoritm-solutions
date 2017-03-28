class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        int cur = 0;
        for (int i = 0; i < nums.size(); i ++) {
            cur += nums[i];
            sum = max(sum, cur);
            if (cur < 0) {
                cur = 0;
            }
        }
        return sum;
    }
};
