/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int low = 0, profit = 0;
        while (1) {
            while (low < int(prices.size()) - 1 && prices[low] >= prices[low + 1]) {
                low ++;
            }
            int high = low + 1;
            while (high < int(prices.size()) - 1 && prices[high] <= prices[high + 1]) {
                high ++;
            }
            if (high < prices.size()) {
                profit += prices[high] - prices[low];
                low = high + 1;
            }
            else {
                break;
            }
        }
        return profit;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> prices({7, 1, 5, 3, 6, 4});
    cout << s.maxProfit(prices);
    return 0;
}
