/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (27.78%)
 * Likes:    6311
 * Dislikes: 965
 * Total Accepted:    624.4K
 * Total Submissions: 2.2M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */

#include <vector>
using namespace std;

// @lc code=start
// reference: https://leetcode.com/problems/median-of-two-sorted-arrays/solutions
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            // swap(nums1, nums2);
            vector<int> tmp = nums1;
            nums1 = nums2;
            nums2 = tmp;
        }
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        int ileft = 0;
        int iright = m;
        while (ileft <= iright) {
            int i = (ileft + iright) / 2;
            int j = (m + n + 1) / 2 - i;
            // increase i
            if (i < m && nums1[i] < nums2[j - 1]) {
                ileft = i + 1;
            }
            // decrease i
            else if (i > 0 && nums1[i - 1] > nums2[j]) {
                iright = i - 1;
            }
            // perfect i
            else {
                int max_left;
                if (i == 0) {
                    max_left = nums2[j - 1];
                } else if (j == 0) {
                    max_left = nums1[i - 1];
                } else {
                    max_left = max(nums2[j - 1], nums1[i - 1]);
                }
                if ((m + n) % 2 == 1) {
                    return max_left;
                }
                int min_right;
                if (i == m) {
                    min_right = nums2[j];
                } else if (j == n) {
                    min_right = nums1[i];
                } else {
                    min_right = min(nums2[j], nums1[i]);
                }
                return (max_left + min_right) / 2.0;
            }
        }
        return 0;
    }
};
// @lc code=end

// Another solution: find the median by divide and conquer
// class Solution {
// public:
//     int kth(int a[], int m, int b[], int n, int k) {
//         if (m < n)
//             return kth(b, n, a, m, k);
//         if (n == 0)
//             return a[k - 1];
//         if (k == 1)
//             return min(a[0], b[0]);

//         int j = min(n, k / 2);
//         int i = k - j;
//         if (a[i - 1] > b[j - 1])
//             return kth(a, i, b + j, n - j, k - j);
//         return kth(a + i, m - i, b, j, k - i);
//     }

//     double findMedianSortedArrays(int a[], int m, int b[], int n) {
//         int k = (m + n) / 2;
//         int m1 = kth(a, m, b, n, k + 1);
//         if ((m + n) % 2 == 0) {
//             int m2 = kth(a, m, b, n, k);
//             return ((double)m1 + m2) / 2.0;
//         }
//         return m1;
//     }
// };
