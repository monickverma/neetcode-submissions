/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    int goodNodes(TreeNode* root) {
        int res = dfs(root, root->val);
        return res;
    }

    int dfs(TreeNode* root, int maxi) {
        if (!root) return 0;

        int count = 0;

        if (root->val >= maxi) {
            count = 1;
            maxi=root->val;
        }

        //maxi = max(maxi, root->val);

        int left = 0, right = 0;
        if (root->left != nullptr) {
            left = dfs(root->left, maxi);
        }
        if (root->right != nullptr) {
            right = dfs(root->right, maxi);
        }
        return count + left + right;
    }
};
