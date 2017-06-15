class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int ans = 0;
        while (index < nums.size()) {
            nums[ans] = nums[index];
            ans ++;
            index ++;
            while (index < nums.size() && nums[index] == nums[index-1]) {
                index ++;
            }
        }
        return ans;
    }
};
