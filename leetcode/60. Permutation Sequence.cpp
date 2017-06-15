class Solution {
public:
    string getPermutation(int n, int k) {
        string nums;
        for (int i = 1; i <= n; i ++) {
            nums.push_back(i+'0');
        }
        while (--k) {
            next_permutation(nums.begin(), nums.end());
        };
        return nums;
    }
};
