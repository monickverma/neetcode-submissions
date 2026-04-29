class Solution {
public:
    TreeNode* lca = nullptr;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findLCA(root, p->val, q->val);
        return lca;
    }

private:
    bool findLCA(TreeNode* root, int p, int q) {
        if (!root) return false;

        int left = findLCA(root->left, p, q) ? 1 : 0;
        int right = findLCA(root->right, p, q) ? 1 : 0;
        int mid = (root->val == p || root->val == q) ? 1 : 0;

        // If any two of mid, left, right are true, this is the LCA
        if (left + right + mid >= 2) {
            lca = root;
        }

        return (left + right + mid) > 0; // Returns true if p or q exists in this subtree
    }
};
