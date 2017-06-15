// brute force: Time Limit Exceeded
class Solution {
public:
    int mySqrt(int x) {
        int ans = 1;
        while (ans <= x / ans) {
            ans ++;
        }
        return ans - 1;
    }
};

// binary search
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
        int left = 0, right = x;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mid == x / mid) {
                return mid;
            }
            else if (mid < x / mid) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left - 1;
    }
};

// newton
int mySqrt(int x) {
    long long r = x;
    while (r*r > x)
        r = (r + x/r) / 2;
    return r;
}
