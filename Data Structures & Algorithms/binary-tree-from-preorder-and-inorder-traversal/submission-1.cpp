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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int,int> inoidxmp;
        for(int i=0;i<inorder.size();i++)
            inoidxmp[inorder[i]]=i;
        
        return split_tree(0,0,preorder.size()-1,inoidxmp,preorder,inorder);
    }

    TreeNode* split_tree(int rootidx,int left,int right,unordered_map<int,int>& inoidxmp,vector<int>& preorder, vector<int>& inorder){
        if(left>right) return nullptr;

        TreeNode* root=new TreeNode(preorder[rootidx]);
        int mid=inoidxmp[preorder[rootidx]];

        if(mid>left)
            root->left=split_tree(rootidx+1,left,mid-1,inoidxmp,preorder,inorder);
        if(right>mid)
            root->right=split_tree(rootidx+ mid-left+1,mid+1,right,inoidxmp,preorder,inorder);
            
        return root;
    }
};
