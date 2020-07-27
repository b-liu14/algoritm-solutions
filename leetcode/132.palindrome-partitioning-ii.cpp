/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

// @lc code=start
// class Solution {
// public:
//     int minCut(string s) {
//         int n = s.size();

//         vector<vector<int>> palindrome(n, vector<int>(n, 1));
//         vector<int> dp(n, 0);
//         for (int l = 2; l <= n; l++) {
//             for (int i = 0; i <= n - l; i++) {
//                 int j = i + l - 1;
//                 palindrome[i][j] = (s[i] == s[j]) && palindrome[i+1][j-1];
//             }
//         }

       
//         for (int j = 1; j < n; j++) {
//             if (palindrome[0][j]) {
//                 dp[j] = 0;
//             }
//             else {
//                 dp[j] = dp[j-1] + 1;
//                 for (int k = 1; k < j; k++) {
//                     if (palindrome[k][j]) {
//                         dp[j] = min(dp[j], dp[k-1] + 1);
//                     }
//                 }
//             }
//         }

//         return dp[n-1];
//     }
// };

// clean solution 
// enumerate the center and shift the length of the palindrome sub-string
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n + 1);
        for(int i = 0; i <= n; i++) {
            cut[i] = i - 1;  // cut[0] = -1, cut[n] = n-1;
        }
        for(int i = 0; i < n; i++) {
            // odd
            for(int j = 0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; j++) {
                cut[i+j+1] = min(cut[i+j+1], 1 + cut[i-j]);
            }
            // even
            for(int j = 0; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) {
                cut[i+j+1] = min(cut[i+j+1], 1 + cut[i-j+1]);
            } 
        }
        return cut[n];
    }
};

// @lc code=end

int main() {
    Solution s;
    cout << s.minCut("abcba");
}
