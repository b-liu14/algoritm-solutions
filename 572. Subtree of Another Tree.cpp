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
    bool equal(TreeNode* s, TreeNode* t) {
        if (s == NULL) {
            return t == NULL;
        }
        else {
            return t!= NULL && s->val == t->val
                && equal(s->left, t->left) && equal(s->right, t->right);
        }
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) {
            return t == NULL;
        }
        else {
            return t != NULL && equal(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
        }

    }
};
