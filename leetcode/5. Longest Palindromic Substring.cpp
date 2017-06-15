// O(N^3)
class Solution {
public:
    bool isPalindromic(string s, int head, int tail) {
        for (int i = head; i <= (tail + head) / 2; i ++) {
            if (s[i] != s[head + tail - i])
                return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans = "";
        for (int head = 0; head < s.length(); head ++) {
            for (int tail = head; tail < s.length(); tail ++) {
                if (tail - head + 1 > ans.length() && isPalindromic(s, head, tail))
                    ans = s.substr(head, tail-head + 1);
            }
        }
        return ans;
    }
};

// O(N^2)
class Solution {
public:
    bool isPalindromic(string s, int head, int tail) {
        for (int i = head; i <= (tail + head) / 2; i ++) {
            if (s[i] != s[head + tail - i])
                return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans = "";
        // odd
        for(int center = 0; center < s.length(); center++) {
            int right = center;
            int left = center;
            while (right + 1 < s.length() && left - 1 >= 0 && s[right + 1] == s[left - 1]) {
                right ++;
                left --;
            }
            int len = right - left + 1;
            if(len > ans.length()) {
                ans = s.substr(left, len);
            }
        }
        // even
        for(int center = 0; center < s.length(); center++) {
            int right = center;
            int left = center+1;
            while (right + 1 < s.length() && left - 1 >= 0 && s[right + 1] == s[left - 1]) {
                right ++;
                left --;
            }
            int len = right - left + 1;
            if(len > ans.length()) {
                ans = s.substr(left, len);
            }
        }
        return ans;
    }
};
// O(N^2) compact
class Solution {
public:
    inline string helper(string s, int left, int right, string ans) {
        while (right + 1 < s.length() && left - 1 >= 0 && s[right + 1] == s[left - 1]) {
            right ++;
            left --;
        }
        int len = right - left + 1;
        return len > ans.length() ?  s.substr(left, len) : ans;
    }
    string longestPalindrome(string s) {
        string ans = "";
        for(int center = 0; center < s.length(); center++) {
            ans = helper(s, center, center, ans);
            ans = helper(s, center+1, center, ans);
        }
        return ans;
    }
};
