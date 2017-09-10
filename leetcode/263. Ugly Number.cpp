class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) {
            return false;
        }
        vector<int> factors = {2, 3, 5};
        for (auto n: factors) {
            while (num % n == 0) {
                num = num / n;
            }
        }
        return num == 1;
    }
};
