// Dynamic programming
class Solution {
public:
    int numDecodings(string s) {
        int len = (int)s.length();
        if (len == 0 || s[0] == '0') {
            return 0;
        }
        int a = 1, b = 1;
        int i = 1;
        while (i < len) {
            int sum = 0;
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2') {
                    sum = a;
                }
                else {
                    sum = 0;
                }
            }
            else {
                sum = b;
                if ((s[i] <= '6' && s[i-1] == '2') || (s[i-1] == '1')) {
                    sum += a;
                }
            }
            a = b;
            b = sum;
            i ++;
        }
        return b;
    }
};
