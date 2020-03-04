/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 *
 * https://leetcode.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (45.96%)
 * Likes:    484
 * Dislikes: 829
 * Total Accepted:    76.1K
 * Total Submissions: 163.8K
 * Testcase Example:  '0'
 *
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and
 * the 6 LEDs on the bottom represent the minutes (0-59).
 * Each LED represents a zero or one, with the least significant bit on the
 * right.
 * 
 * For example, the above binary watch reads "3:25".
 * 
 * Given a non-negative integer n which represents the number of LEDs that are
 * currently on, return all possible times the watch could represent.
 * 
 * Example:
 * Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04",
 * "0:08", "0:16", "0:32"]
 * 
 * 
 * Note:
 * 
 * The order of output does not matter.
 * The hour must not contain a leading zero, for example "01:00" is not valid,
 * it should be "1:00".
 * The minute must be consist of two digits and may contain a leading zero, for
 * example "10:2" is not valid, it should be "10:02".
 * 
 * 
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
    int num1(int num) {
        int n = 0;
        while (num > 0) {
            n++;
            num -= (num & -num);
        }
        return n;
    }

public:
    vector<string> readBinaryWatch(int num) {
        vector<vector<int>> n_LED_h{4, vector<int>{}}, n_LED_min{6, vector<int>{}};
        for (int i = 0; i < 12; i++) {
            n_LED_h[num1(i)].push_back(i);
        }
        for (int i = 0; i < 60; i++) {
            n_LED_min[num1(i)].push_back(i);
        }

        vector<string> ans;
        for (int i = 0; i < 4; i++) {
            if (num - i < 0 || num - i >= 6) {
                continue;
            }
            for (auto h : n_LED_h[i]) {
                for (auto min : n_LED_min[num - i]) {
                    auto min_str = to_string(min);
                    if (min_str.size() < 2) {
                        min_str = "0" + min_str;
                    }
                    ans.push_back(to_string(h) + ":" + min_str);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

int main() {
    Solution s;
    auto ret = s.readBinaryWatch(8);
    for (auto str : ret) {
        cout << str << ", ";
    }
    cout << endl;

    return 0;
}