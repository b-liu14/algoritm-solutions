class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i ++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i = 0; i < n; i ++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n+1;
    }
};

// cheating solution using sort
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        for (; i < nums.size(); i ++) {
            if (nums[i] > 0) {
                break;
            }
        }
        int count = 1;
        for (; i < nums.size(); i ++) {
            if (nums[i] == count - 1) continue;
            if (nums[i] != count) {
                return count;
            }
            count ++;
        }
        return count;
    }
};
