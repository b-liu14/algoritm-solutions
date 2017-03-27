// my slow solution
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
            bool same = false;
            for (int j = index; j < i; j ++) {
                if (nums[j] == nums[i]) {
                    same = true;
                }
            }
            if (same) continue;
            int &v = nums[i];
            cur.push_back(v);
            swap(v, nums[index]);
            dfs(nums, index + 1);
            cur.pop_back();
            swap(v, nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size()) dfs(nums, 0);
        return ans;
    }
};


// Modified solutions from https://leetcode.com/problems/permutations-ii/#/solutions

// the most elegant one. the key point is:
//  1. do not use reference for num.
//  2. do not swap back nums[i] and nums[j].
// It's not easy to understand for me
class Solution {
public:
    void recursion(vector<int> num, int i, vector<vector<int>> &res) {
        if (i == num.size() - 1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < num.size(); k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, res);
        return res;
    }
};
