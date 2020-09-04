/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (43.07%)
 * Likes:    2008
 * Dislikes: 70
 * Total Accepted:    347.7K
 * Total Submissions: 738.4K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 * 
 * 
 * Return:
 * 
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
 */

#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
public:
    void dfs(TreeNode* root, int sum, vector<int>& cur, vector<vector<int>>& all) {
        cur.push_back(root->val);

        // leaf node
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) {
                all.push_back(cur);
            }
        } else {
            sum -= root->val;
            if (root->left) {
                dfs(root->left, sum, cur, all);
            }
            if (root->right) {
                dfs(root->right, sum, cur, all);
            }
        }

        cur.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> all;
        vector<int> cur;

        if (root != nullptr) {
            dfs(root, sum, cur, all);
        }

        return all;
    }
};
// @lc code=end
