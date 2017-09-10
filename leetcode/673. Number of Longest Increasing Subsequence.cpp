class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<vector<pair<int, int>>> vec;
        for (int i = 0; i < nums.size(); i ++) {
            bool pushed = false;
            for (int j = 0; j < vec.size(); j ++) {
                if (vec[j].back().first >= nums[i]) {
                    int n = 0;
                    if (j == 0) n = 1;
                    else {
                        for (int k = 0; k < vec[j-1].size(); k ++)
                            if (vec[j-1][k].first < nums[i])
                                n += vec[j-1][k].second;
                    }
                    vec[j].push_back(make_pair(nums[i], n));
                    pushed = true;
                    break;
                }
            }
            if (pushed == false) {
                int n = 0;
                if (i == 0) n = 1;
                else {
                    for (int k = 0; k < vec.back().size(); k ++)
                        if (vec.back()[k].first < nums[i])
                            n += vec.back()[k].second;
                }
                pair<int, int> p = make_pair(nums[i], n);
                vector<pair<int, int>> tmp = {p};
                vec.push_back(tmp);
            }
        }
        int ans = 0;
        for (int i = 0; i < vec.back().size(); i ++) {
            ans += vec.back()[i].second;
        }
        return ans;
    }
};
