class Solution {
public:
    // get [L, R)
    int getfBound(vector<int>& nums, int target, string type) {
        int lo = 0, hi = (int)nums.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;

            if (nums[mid] > target) {
                hi = mid;
            }
            else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                if (type == "left") {
                    hi = mid;
                }
                else {
                    lo = mid + 1;
                }
            }
        }
        return lo;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        ans[0] = getfBound(nums, target, "left");
        ans[1] = getfBound(nums, target, "right") - 1;
        if (ans[0] > ans[1]) {
            ans[0] = -1;
            ans[1] = -1;
        }
        return ans;
    }
};
