class Solution {
    vector<int> nums;

public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }

    int pick(int target) {
        int n = 0, ans = -1;
        for (int i = 0; i < nums.size(); i ++) {
            if(nums[i] != target)
                continue;
            else {
                n++;
                if(ans == -1 || rand() % n == 0) {
                    ans = i;
                }
            }
        }
        return ans;
    }
};
