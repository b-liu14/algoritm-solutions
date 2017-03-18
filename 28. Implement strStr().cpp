class Solution {
public:
    bool isPrefix(string haystack, string needle) {
        if (haystack.length() < needle.length()) {
            return false;
        }
        for (int i = 0; i < needle.length(); i ++) {
            if (haystack[i] != needle[i]) {
                return false;
            }
        }
        return true;
    }
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        for (int i = 0; i <= (int)haystack.length() - (int)needle.length(); i ++) {
            if (isPrefix(haystack.substr(i), needle)) {
                return i;
            }
        }
        return -1;
    }
};
