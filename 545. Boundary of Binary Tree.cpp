class Solution {
public:
    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }
    // get left boundary without leaf
    void lb(TreeNode* root, vector<int>& cur) {
        if (!root || isLeaf(root)) return;
        cur.push_back(root->val);
        if (root->left) {
            lb(root->left, cur);
        }
        else {
            lb(root->right, cur);
        }
    }
    // get right boundary without leaf in revere order
    void rb(TreeNode* root, vector<int>& cur) {
        if (!root || isLeaf(root)) return;
        if (root->right) {
            rb(root->right, cur);
        }
        else {
            rb(root->left, cur);
        }
        cur.push_back(root->val);
    }
    // get leaves
    void leaf(TreeNode* root, vector<int>& cur) {
        if (!root) return;
        if (isLeaf(root)) {
            cur.push_back(root->val);
            return;
        }
        leaf(root->left, cur);
        leaf(root->right, cur);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        std::vector<int> ans;
        if (root) {
            ans.push_back(root->val);
            lb(root->left, ans);
            leaf(root->left, ans);
            leaf(root->right, ans);
            rb(root->right, ans);
        }
        return ans;
    }
};
