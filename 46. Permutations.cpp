class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    void dfs(vector<int>& nums, int index) {
        if (index == nums.size()) {
            ans.push_back(cur);
            return;
        }
        for (int i = index; i < nums.size(); i ++) {
            int &v = nums[i];
            cur.push_back(v);
            swap(v, nums[index]);
            dfs(nums, index + 1);
            cur.pop_back();
            swap(v, nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size()) dfs(nums, 0);
        return ans;
    }
};
