// my stupid solution:
class Solution {
public:
    int depth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(depth(root->left), depth(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return max(diameterOfBinaryTree(root->left),
            max(diameterOfBinaryTree(root->right),
                depth(root->left) + depth(root->right)));
    }
};

// elegant solution from affah
class Solution {
public:
    int ans;
    int dfs(TreeNode *c)
    {
        if(!c)
            return -1;
        int lh = dfs(c->left) + 1, rh = dfs(c->right) + 1;
        ans = max(ans, lh + rh);
        return max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
