class Solution {
public:
    bool isPalindrome(int x) {
        return (x >= 0 && reverse(x) == x);
    }
    int reverse(int x) {
        bool neg = (x < 0);
        x = abs(x);
        int ans = 0;
        while(x > 0) {
            int c = x % 10;
            if (ans > (INT_MAX - c) / 10) {
                return 0;
            }
            ans = ans * 10 + c;
            x /= 10;
        }

        return neg ? -ans : ans;
    }
};
