class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1/x;
        double tmp = myPow(x, n/2);
        return tmp * tmp * myPow(x, n % 2);    }
};
