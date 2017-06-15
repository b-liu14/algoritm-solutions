class Solution {
public:
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

// short solution using long long
class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(x != 0) {
            ans = ans * 10 + x % 10;
            x /= 10;
            if (ans > INT_MAX || ans < INT_MIN) {
                return 0;
            }
        }
        return (int)ans;
    }
};
