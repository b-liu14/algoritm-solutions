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

        cur.push_back(candidates[index]);
        dfs(candidates, target - candidates[index], index + 1);
        cur.pop_back();

        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) {
            index ++;
        }
        dfs(candidates, target, index + 1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return ans;
    }
};
