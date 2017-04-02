// warning: 1337^3 > INT_MAX
class Solution {
public:
    int myPow(int x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        int tmp = myPow(x, n/2) % 1337;
        return (tmp * tmp % 1337) * myPow(x, n % 2) % 1337;
    }
    int superPow(int a, vector<int>& b) {
        int ans = 1;
        a %= 1337;
        for (int i = 0; i < b.size(); i ++) {
            ans = myPow(ans, 10) * myPow(a, b[i]) % 1337;
        }
        return ans;
    }
};

// python version
class Solution(object):
    def superPow(self, a, b):
        """
        :type a: int
        :type b: List[int]
        :rtype: int
        """
        c = 1
        for n in b:
             c = c ** 10 * a ** n % 1337
        return c
