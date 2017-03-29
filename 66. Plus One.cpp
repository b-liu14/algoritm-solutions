class Solution {
public:
    vector<int> reverse(vector<int>& digits) {
        for (int i = 0; i < digits.size() / 2; i ++) {
            swap(digits[i], digits[digits.size() - i - 1]);
        }
        return digits;
    }
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits);
        int c = 1;
        int cur = 0;
        while (c != 0) {
            if (cur >= digits.size()) {
                digits.push_back(0);
            }
            int sum = digits[cur] + c;
            digits[cur] = sum % 10;
            c = sum / 10;
            cur ++;
        }
        reverse(digits);
        return digits;
    }
};
