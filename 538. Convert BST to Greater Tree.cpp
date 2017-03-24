// my stupid solution
class Solution {
public:
    map<TreeNode*, int> m;
    int gsum(TreeNode* root, int val) {
        if (root == NULL) {
            return 0;
        }
        int tmp = root->val < val ? 0 : root->val;
        return tmp + gsum(root->left, val) + gsum(root->right, val);
    }
    void pre(TreeNode* root, TreeNode* realRoot) {
        if (root) {
            m[root] = gsum(realRoot, root->val);
            pre(root->left, realRoot);
            pre(root->right, realRoot);
        }
    }
    void convert(TreeNode* root) {
        if (root) {
            root->val = m[root];
            convert(root->left);
            convert(root->right);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        // convert(root, NULL, NULL, false, false);
        pre(root, root);
        convert(root);
        return root;
    }
};

// elegant solution from affah:
class Solution {
public:
    int sum;
    void dfs(TreeNode *root)
    {
        if(!root)
            return;
        dfs(root->right);
        int t = root->val;
        root->val += sum;
        sum += t;
        dfs(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        dfs(root);
        return root;
    }
};
