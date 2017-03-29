class Solution {
public:
    int climbStairs(int n) {
        int fn2 = 1, fn1 = 1;
        for (int i = 2; i <= n; i ++) {
            int fn = fn1 + fn2;
            fn2 = fn1;
            fn1 = fn;
        }
        return fn1;
    }
};
