class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step = 0;
        int cur = 0;
        while (cur < nums.size() - 1) {
            step ++;
            if (cur + nums[cur] >= nums.size() - 1) {
                return true;
            }
            int to = cur;
            for (int i = 1; i <= nums[cur]; i ++) {
                if (nums[cur + i] + i > to - cur + nums[to]) {
                    to = i+cur;
                }
            }
            if (cur == to) {
                return false;
            }
            cur = to;
        }
        return true;
    }
};
