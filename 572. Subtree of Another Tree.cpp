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
            if (t == NULL) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if (t == NULL) {
                return false;
            }
            else {
                return s->val == t->val && equal(s->left, t->left) && equal(s->right, t->right);
            }
        }
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == NULL) {
            if (t == NULL) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if (t == NULL) {
                return false;
            }
            else {
                return equal(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
            }
        }

    }
};
