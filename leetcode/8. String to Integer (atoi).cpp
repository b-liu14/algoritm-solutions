class Solution {
public:
    int myAtoi(string str) {
        int index = 0;
        // strip
        while (isspace(str[index])) {
            index ++;
        }
        int ans = 0;
        bool neg = false;
        // get sign
        if(str[index] == '-') {
            neg = true;
            index ++;
        }
        else if(str[index] == '+') {
            neg = false;
            index ++;
        }
        // get abs value
        while (isdigit(str[index])) {
            int tmp = str[index] - '0';
            // overflow?
            if ((INT_MAX - tmp) / 10 < ans) {
                return neg ? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + tmp;
            index ++;
        }
        // return value
        return neg ? -ans : ans;
    }
};
