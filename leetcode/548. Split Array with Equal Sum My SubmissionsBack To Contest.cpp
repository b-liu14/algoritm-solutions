// O(N^3) with prune
class Solution {
public:
    vector<int> bf(vector<int>& sum, int begin, int s) {
        vector<int> v;
        for (int i = begin+1; i < sum.size(); i ++) {
            int tmp = sum[i - 1] - sum[begin - 1];
            if (tmp == s) v.push_back(i);
        }
        return v;
    }
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n, 0);
        for (int i = 0; i < n; i ++) {
            int tmp = i == 0 ? 0 : sum[i-1];
            sum[i] = nums[i] + tmp;
        }
        for (int i = 1; i < n; i ++) {
            int s = i == 0 ? 0 : sum[i-1];
            if (i > 1 && sum[i] == sum[i-1] && sum[i] == sum[i-2]) continue;
            for (int j: bf(sum, i+1, s)) {
                for (int k: bf(sum, j+1, s)) {
                    if (sum[n-1] - sum[k] == s) return true;
                }
            }
        }
        return false;
    }
};

// O(N^2) using hash set
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 7) return false;
        vector<int> sum(n, nums[0]);
        for (int i = 1; i < n; i ++) {
            sum[i] = nums[i] + sum[i-1];
        }
        for (int j = 1; j < n; j ++) {
            unordered_set<int> hash;
            for (int i = 1; i < j - 1; i ++) {
                if (sum[i-1] == sum[j-1] - sum[i]) {
                    hash.insert(sum[i-1]);
                }
            }
            for (int k = j+2; k < n - 1; k ++) {
                int s = sum[n-1] - sum[k];
                if (s == sum[k-1] - sum[j] && hash.count(s) == 1) {
                    return true;
                }
            }
        }
        return false;
    }
};
