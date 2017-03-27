class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    void dfs(vector<int>& candidates, int target, int index) {
        if (0 == target) {
            ans.push_back(cur);
            return;
        }
        if (index >= candidates.size() || target < 0) {
            return;
        }
        dfs(candidates, target, index + 1);

        cur.push_back(candidates[index]);
        dfs(candidates, target - candidates[index], index);
        cur.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return ans;
    }
};
