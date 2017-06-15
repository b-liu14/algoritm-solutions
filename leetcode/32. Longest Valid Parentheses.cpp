// my solution using map
class Solution {
public:
    int longestValidParentheses(string s) {
        int nLeft = 0;
        int ans = 0;
        map<int, int> left;
        left[0] = -1;
        for (int i = 0; i < s.length(); i ++) {
            if (s[i] == '(') {
                nLeft ++;
                if (left.find(nLeft) == left.end()) {
                    left[nLeft] = i;
                }
            }
            else {
                if (nLeft > 0) {
                    left.erase(nLeft);
                    nLeft --;
                    ans = max(ans, i - left[nLeft]);
                }
                else {
                    left.clear();
                    left[0] = i;
                }
            }
        }
        return ans;
    }
};

// solution using DP from https://leetcode.com/problems/longest-valid-parentheses/#/solutions
class Solution {
public:
    int longestValidParentheses(string s) {
        int curMax = 0;
        vector<int> longest(s.size(),0);
        for(int i=1; i < s.length(); i++){
            int left = i-longest[i-1]-1;
            if(s[i] == ')' && left >= 0 && s[left] == '(') {
                    int tmp = (left >= 1) ? longest[left-1] : 0
                    longest[i] = longest[i-1] + 2 + tmp;
                    curMax = max(longest[i], curMax);
                }
            }
            //else if s[i] == '(', skip it, because longest[i] must be 0
        }
        return curMax;
    }
};
