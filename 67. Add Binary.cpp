class Solution {
public:
    string reverse(string& str) {
        for (int i = 0; i < str.size() / 2; i ++) {
            swap(str[i], str[str.size() - i - 1]);
        }
        return str;
    }
    inline int get(string& str, int index) {
        if (index < 0 || index >= str.length()) {
            return 0;
        }
        else return str[index] - '0';
    }
    string addBinary(string a, string b) {
        reverse(a);
        reverse(b);
        int maxL = max(a.length(), b.length());
        string ans(maxL, '0');
        int c = 0;
        for (int i = 0; i < maxL; i ++) {
            int sum = get(a, i) + get(b, i) + c;
            ans[i] = sum % 2 + '0';
            c = sum / 2;
        }
        if (c) {
            ans.push_back('1');
        }
        return reverse(ans);
    }
};
