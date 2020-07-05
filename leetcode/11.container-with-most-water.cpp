/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (47.66%)
 * Likes:    6048
 * Dislikes: 581
 * Total Accepted:    652K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * 
 * 
 * 
 * 
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49. 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 */

// @lc code=start
// brute froce O(N^2) time exceed
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int len = height.size();
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                int area = (j - i) * min(height[i], height[j]);
                ans = ans < area ? area : ans;
            }
        }
        return ans;
    }
};
// brute force 1 O(N^2) AC
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int len = height.size();

        vector<int> next(len, len);
        int cur = 0;
        for (int i = 1; i < len; i++) {
            if (height[i] > height[cur]) {
                next[cur] = i;
                cur = i;
            }
        }

        for (int i = 0; i < len; i = next[i]) {
            for (int j = i + 1; j < len; j++) {
                int area = (j - i) * min(height[i], height[j]);
                ans = ans < area ? area : ans;
            }
        }
        return ans;
    }
};
// simple greed
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            ans = max(ans, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return ans;
    }
};
// optimized greed O(N) AC
class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int len = height.size();

        int left = 0;
        int right = len - 1;
        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            ans = ans < area ? area : ans;
            if (height[left] < height[right]) {
                int tmp = left + 1;
                while (tmp < len && height[tmp] <= height[left])
                    tmp++;
                left = tmp;
            } else {
                int tmp = right - 1;
                while (tmp >= 0 && height[tmp] <= height[right])
                    tmp--;
                right = tmp;
            }
        }
        return ans;
    }
};
// @lc code=end
