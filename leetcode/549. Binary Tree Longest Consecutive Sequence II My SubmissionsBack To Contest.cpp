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
    map<pair<int, TreeNode*>, int> d;
    int down(int diff, TreeNode* root) {
        // 记忆化？
        if (d.count({diff, root}) == 1) {
            return d[{diff, root}];
        }
        int ans = 0;
        for (auto node : {root->left, root->right}) {
            if (node && (node->val == root->val + diff)) {
                ans = max(ans, 1 + down(diff, node));
            }
        }
        d[{diff, root}] = ans;
        return ans;
    }
    int longestConsecutive(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int ans = 1;
        for (int diff : {-1, 1}) {
            ans += down(diff, root);
        }
        return max(max(longestConsecutive(root->left), longestConsecutive(root->right)), ans);
    }
};
