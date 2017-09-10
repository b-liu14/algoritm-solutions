class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, min_ = INT_MAX, max_ = INT_MIN;
        while (left < nums.size() - 1 && nums[left] <= nums[left+1]) left ++;
        while (right > 0 && nums[right] >= nums[right-1]) right --;
        for (int i = left+1; i < nums.size(); i ++) min_ = min(min_, nums[i]);
        for (int i = right-1; i >= 0; i --) max_ = max(max_, nums[i]);
        int i = 0, j = nums.size() - 1;
        while (nums[i] <= min_) i ++;
        while (nums[j] >= max_) j --;
        return max(0, j - i + 1);
    }
};
