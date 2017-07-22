// dp
const int mod = 1000000000 + 7;
class Solution {
public:
    int valid_code(string s) {
        if (s[0] == '*' || s[0] == '1' || (s[0] == 2 && s[1] <= '6')) {
            return true;
        }
        return false;
    }
    int mul(int a, int b) {
        return int(((long long)a * b) % mod);
    }
    int add(int a, int b) {
        return (a + b) % mod;
    }
    int numDecodings(string s) {
        int len = (int)s.length();
        if (len == 0 || s[0] == '0') {
            return 0;
        }
        int a = 1, b = 1;
        int i = 0;
        while (i < len) {
            int sum = 0;
            if (s[i] == '*') {
                sum = mul(9, b);
            } else if (s[i] != '0') {
                sum = b;
            }

            if (i > 0) {
                string tmp = s.substr(i-1, 2);
                if (tmp == "**") {
                    sum += mul(15, a);
                }
                else if (tmp[0] == '*') {
                    sum += mul(1 + (tmp[1] <= '6'), a);
                }
                else if (tmp[1] == '*') {
                    sum += mul((tmp[0] == '1') * 9 + (tmp[0] == '2') * 6, a);
                }
                else {
                    sum += mul((stoi(tmp) <= 26) && tmp[0] != '0', a);
                }
            }
            a = b;
            b = sum % mod;
            i ++;
        }
        return b;
    }
};
