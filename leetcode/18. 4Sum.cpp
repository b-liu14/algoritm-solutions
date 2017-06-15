class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int len = nums.size();
        for (int i = 0; i < len; i ++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for (int j = i+1; j < len; j ++) {
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                }
                int left = j+1, right = len - 1;
                int curTarget = target - nums[i] - nums[j];
                while (left < right) {
                    int sum = nums[left] + nums[right];
                    if (sum < curTarget) {
                        left ++;
                    }
                    else if (sum > curTarget) {
                        right --;
                    }
                    else {
                       ans.push_back(vector<int>({nums[i], nums[j], nums[left ++], nums[right --]}));
                       while (left < right && nums[left] == nums[left-1]) {
                           left ++;
                       }
                       while (left < left && nums[right] == nums[right+1]) {
                           right --;
                       }
                    }
                }
            }
        }
        return ans;
    }
};
