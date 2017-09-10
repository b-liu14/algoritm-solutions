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
   void dfs(TreeNode* root, vector<int>& vec) {
        if (root != NULL) {
            dfs(root->left, vec);
            vec.push_back(root->val);
            dfs(root->right, vec);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        dfs(root, vec);
        return vec;
    }
};
