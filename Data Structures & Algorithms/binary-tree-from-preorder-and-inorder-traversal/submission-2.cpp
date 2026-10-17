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
    unordered_map<int, int> indidxmp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            indidxmp[inorder[i]] = i;
        }

        return split_tree(0, 0, n - 1, preorder, inorder);
    }
    TreeNode* split_tree(int rootidx, int left, int right, vector<int>& pr, vector<int>& in) {
        if (left > right) return nullptr;

        int mid = indidxmp[pr[rootidx]]; // index of current root in inorder array

        TreeNode* root = new TreeNode(pr[rootidx]);
        if (mid > left) {
            root->left = split_tree(rootidx + 1, left, mid - 1, pr, in);
        }
        if (right > left) {
            root->right = split_tree(rootidx+mid-left+1, mid+1, right, pr, in);
        }
        return root;
    }
};
