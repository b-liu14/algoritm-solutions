class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ret;
        for (int i = n; i > k+1; i --) {
            ret.push_back(i);
        }
        int small = 1;
        int big = k+1;
        while (big > small) {
            ret.push_back(big);
            ret.push_back(small);
            big --;
            small ++;
        }
        if (small == big) {
            ret.push_back(big);
        }
        return ret;
    }
};
