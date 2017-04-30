class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> sums;
        for (int i = 0; i < nums.size(); i ++) {
            sums.push_back((i == 0 ? 0 : sums[i-1]) + nums[i]);
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = i; j < nums.size(); j ++) {
                if (sums[j] - sums[i] + nums[i] == k) {
                    ans ++;
                }
            }
        }
        return ans;
    }
};
