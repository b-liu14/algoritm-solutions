class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int len = nums.size();
        for (int i = 0; i < len; i ++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i+1, right = len - 1;
            int curTarget = -nums[i];
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum < curTarget) {
                    left ++;
                }
                else if (sum > curTarget) {
                    right --;
                }
                else {
                   ans.push_back(vector<int>({nums[i], nums[left ++], nums[right --]}));
                   while (left < right && nums[left] == nums[left-1]) {
                       left ++;
                   }
                   while (left < left && nums[right] == nums[right+1]) {
                       right --;
                   }
                }
            }
        }
        return ans;
    }
};

// two sum using standard two pointer algorithm
vector<vector<int>> twoSum(vector<int>& nums, int curTarget) {
    vector<vector<int>> ans;
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum < curTarget) {
            left ++;
        }
        else if (sum > curTarget) {
            right --;
        }
        else {
           ans.push_back(vector<int>({left ++, right --}));
           while (left < right && nums[left] == nums[left-1]) {
               left ++;
           }
           while (left < left && nums[right] == nums[right+1]) {
               right --;
           }
        }
    }
    return ans;
}
