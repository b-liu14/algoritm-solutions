// Short but clever solution
class Solution {
public:
    int findIntegers(int num) {
        int f[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; i ++) {
            f[i] = f[i-1] + f[i-2];
        }
        int i = 30, ans = 0, pre_sign = 0;
        while (i >= 0) {
            if ((num & (1 << i)) != 0) {
                ans += f[i];
                if (pre_sign == 1) {
                    ans --;
                    break;
                }
                pre_sign = 1;
            }
            else {
                pre_sign = 0;
            }
            i --;
        }
        return ans + 1;
    }
};
