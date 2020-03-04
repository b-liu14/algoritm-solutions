/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (44.95%)
 * Likes:    3297
 * Dislikes: 79
 * Total Accepted:    556.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <functional>
#include <stack>
using namespace std;

class Solution {
public:
    // recursively
    // bool cmp(const TreeNode* left, const TreeNode* right) {
    //     if (left == nullptr || right == nullptr) {
    //         return left == nullptr && right == nullptr;
    //     } else if (left->val != right->val) {
    //         return false;
    //     } else {
    //         return cmp(left->left, right->right) && cmp(left->right, right->left);
    //     }
    // }
    // bool isSymmetric(TreeNode* root) {
    //     return root == nullptr || cmp(root->left, root->right);
    // }

    // iteratively
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        stack<pair<TreeNode*, TreeNode*>> s;
        auto p = make_pair(root->left, root->right);
        s.push(p);
        while (!s.empty()) {
            auto p = s.top();
            s.pop();
            if (p.first == nullptr && p.second == nullptr) {
                continue;
            } else if (p.first == nullptr || p.second == nullptr) {
                return false;
            } else if (p.first->val != p.second->val) {
                return false;
            } else {
                s.push(make_pair(p.first->left, p.second->right));
                s.push(make_pair(p.first->right, p.second->left));
            }
        }
        return true;
    }
};
// @lc code=end
