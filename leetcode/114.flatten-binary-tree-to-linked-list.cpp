/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (45.12%)
 * Likes:    2200
 * Dislikes: 274
 * Total Accepted:    302.7K
 * Total Submissions: 651.1K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example, given the following tree:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 
 * The flattened tree should look like:
 * 
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
 * 
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
class Solution {
public:
    // TreeNode* flatten_helper(TreeNode* root) {
    //     if (root->left == NULL && root->right == NULL) {
    //         return root;
    //     } else if (root->left == NULL) {
    //         return flatten_helper(root->right);
    //     } else if (root->right == NULL) {
    //         root->right = root->left;
    //         root->left = NULL;
    //         return flatten_helper(root->right);
    //     } else {
    //         auto right = root->right;
    //         root->right = root->left;
    //         root->left = NULL;
    //         auto tail = flatten_helper(root->right);
    //         tail->right = right;
    //         auto tail_new = flatten_helper(right);
    //         return tail_new;
    //     }
    // }
    // void flatten(TreeNode* root) {
    //     if (root != NULL) {
    //         flatten_helper(root);
    //     }
    // }
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        flatten(root->left);
        flatten(root->right);
        if (root->left != nullptr) {
            auto right = root->right;
            root->right = root->left;
            root->left = nullptr;
            do {
                root = root->right;
            } while (root->right != nullptr);
            root->right = right;
        }
    }
};
// @lc code=end
