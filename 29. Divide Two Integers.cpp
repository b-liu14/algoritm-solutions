class Solution {
public:
    int getSign(int n) {
        if (n == 0) return 0;
        if (n > 0) return 1;
        return -1;
    }
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return INT_MAX;
        }
        int sign =  getSign(dividend) * getSign(divisor); // 0 -> zero, 1 -> positive, -1-> negetive.
        long long ded = abs((long long)dividend);
        long long dor = abs((long long)divisor);
        long long ans = 0;
        for (int nshift = 31; nshift >= 0; nshift --) {
            if (dor <= ((long long)1 << (31 - nshift))) {
                long long tmp = dor << nshift;
                if (ded >= tmp) {
                    ans += (long long) 1 << nshift;
                    ded = ded - tmp;
                }
            }
        }
        if (sign == 1) {
            return ans > INT_MAX ? INT_MAX : (int)ans;
        }
        else {
            return (int) -ans;
        }
    }
};
