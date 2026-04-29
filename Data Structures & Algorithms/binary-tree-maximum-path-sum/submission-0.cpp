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
    int maxPathSum(TreeNode* root) {
        	
	int res=root->val;
    dfs(root,res);
    return res;
    
    }

    int dfs(TreeNode* root, int& res){
        if(!root) return 0;

        int left_max=max(dfs(root->left,res),0);
        int right_max=max(dfs(root->right,res),0);

        res=max(res,left_max+right_max+root->val);
        return root->val+max(left_max,right_max);
    }

};
