class Solution {
public:
    string countAndSay(int n) {
        if (n <= 1) {
            return "1";
        }
        string str = countAndSay(n-1);
        string ans;
        int left = 0;
        while (left < str.length()) {
            int right = left + 1;
            while (right < str.length() && str[right] == str[left]) {
                right ++;
            }
            ans += to_string(right-left) + str[left];
            left = right;
        }
        return ans;
    }
};
