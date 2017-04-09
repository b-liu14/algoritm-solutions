class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> v;
        while (n) {
            v.push_back(n % 10);
            n /= 10;
        }
        int ans = -1;
        if (next_permutation(v.rbegin(), v.rend())) {
            ans = 0;
            for (int i = v.size() - 1; i >= 0; i --) {
                if ((INT_MAX - v[i]) / 10 < ans) return -1;
                ans = ans * 10 + v[i];
            }
        }
        return ans;
    }
};
