class Solution {
public:
    string strip(string s) {
        int left = 0;
        while (left < s.length() && isspace(s[left])) {
            left ++;
        }
        int right = s.length() - 1;
        while (right > left && isspace(s[right])) {
            right --;
        }
        return s.substr(left, right - left + 1);
    }
    bool processInt(string s, int& index) {
        if (index < s.length() && (s[index] == '+' || s[index] == '-')) {
            index ++;
        }
        return processUInt(s, index);
    }
    bool processUInt(string s, int& index) {
        int left = index;
        while (index < s.length() && isdigit(s[index])) {
            index ++;
        }
        return index > left;
    }
    bool processFloat(string s, int& index) {
        bool intPart = processInt(s, index);
        bool floatPart = false;
        if (index < s.length() && s[index] == '.') {
            floatPart = processUInt(s, ++ index);
        }
        return intPart || floatPart;
    }
    bool isNumber(string s) {
        s = strip(s);
        int index = 0;
        if (! processFloat(s, index)) return false;
        // scientific?
        if (index < s.length() && s[index] == 'e') {
            if (! processInt(s, ++ index)) return false;
        }
        return index == s.length();
    }
};
