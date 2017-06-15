class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int ans = nums[0] + nums[1] + nums[2];
        int len = nums.size();
        for (int i = 0; i < len; i ++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i+1, right = len - 1;
            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum < target) {
                    left ++;
                }
                else if (sum > target) {
                    right --;
                }
                else {
                   return target;
                }
                if (abs(target-ans) > abs(target-sum)) {
                    ans = sum;
                }
            }
        }
        return ans;
    }
};
