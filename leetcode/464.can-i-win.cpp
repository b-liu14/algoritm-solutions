/*
 * @lc app=leetcode id=464 lang=cpp
 *
 * [464] Can I Win
 *
 * https://leetcode.com/problems/can-i-win/description/
 *
 * algorithms
 * Medium (28.18%)
 * Likes:    826
 * Dislikes: 146
 * Total Accepted:    46.4K
 * Total Submissions: 162.9K
 * Testcase Example:  '10\n11'
 *
 * In the "100 game," two players take turns adding, to a running total, any
 * integer from 1..10. The player who first causes the running total to reach
 * or exceed 100 wins. 
 * 
 * What if we change the game so that players cannot re-use integers? 
 * 
 * For example, two players might take turns drawing from a common pool of
 * numbers of 1..15 without replacement until they reach a total >= 100.
 * 
 * Given an integer num_max and another integer desiredTotal,
 * determine if the first player to move can force a win, assuming both players
 * play optimally. 
 * 
 * You can always assume that num_max will not be larger than 20
 * and desiredTotal will not be larger than 300.
 * 
 * 
 * Example
 * 
 * Input:
 * num_max = 10
 * desiredTotal = 11
 * 
 * Output:
 * false
 * 
 * Explanation:
 * No matter which integer the first player choose, the first player will lose.
 * The first player can choose an integer from 1 up to 10.
 * If the first player choose 1, the second player can only choose integers
 * from 2 up to 10.
 * The second player will win by choosing 10 and get a total = 11, which is >=
 * desiredTotal.
 * Same with other integers chosen by the first player, the second player will
 * always win.
 * 
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
// backtrack with memorize
class Solution {
public:
    bool dfs(int num_max, unsigned int state, int* mem, int desiredTotal) {
        // already compuated, just return
        if (mem[state] >= 0) {
            return mem[state];
        }

        if (desiredTotal <= 0) {
            mem[state] = 0;
            return false;
        }
        int mask = 1 << (num_max - 1);
        for (int i = num_max; i > 0; i--) {
            // if visited before, continue
            if (!(state & mask) && !dfs(num_max, state | mask, mem, desiredTotal - i)) {
                mem[state] = 1;
                return true;
            }
            mask >>= 1;
        }

        mem[state] = 0;
        return false;
    }
    bool canIWin(int num_max, int desiredTotal) {
        if (num_max >= desiredTotal) {
            return true;
        }
        int sum = (num_max + 1) * num_max / 2;
        if (sum < desiredTotal) {
            return false;
        } else if (sum == desiredTotal) {
            return num_max % 2;
        }

        // key: bit map state
        // value: 0 not compuated, 1 can win, -1 can not win
        int n = 1 << num_max;
        int mem[n];
        fill(mem, mem + n, -1);
        return dfs(num_max, 0, mem, desiredTotal);
    }
};
// @lc code=end

int main() {
    Solution s;

    int n = 6;
    for (int i = 0; i <= n * (n + 1) / 2; i++) {
        cout << n << " " << i << " " << s.canIWin(n, i) << endl;
    }

    cout << s.canIWin(18, 79) << endl;
    cout << s.canIWin(10, 0);

    return 0;
}