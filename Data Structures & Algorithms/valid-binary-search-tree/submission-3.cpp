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
    bool isValidBST(TreeNode* root) {
        return dfs(root,LONG_MIN,LONG_MAX);

    }

    int dfs(TreeNode* root,long low,long high){
        if(!root) return true;

        long val=root->val;
        if(val<=low || val>=high) return false;

        return dfs(root->left,low,val) && dfs(root->right,val,high);
    }
};
