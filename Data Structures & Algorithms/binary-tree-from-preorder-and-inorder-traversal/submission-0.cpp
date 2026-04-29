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

        for(int i=0;i<inorder.size();i++){
            inoidxmp[inorder[i]]=i;
        }

        return split_tree(preorder,inoidxmp,0,0,inorder.size()-1);
        
        
    }

    TreeNode* split_tree(vector<int>& preorder,  unordered_map<int,int> inoidxmp,int rootidx,int left,int right){

        if (left > right) return nullptr;

        TreeNode* root= new TreeNode(preorder[rootidx]);

        int mid=inoidxmp[preorder[rootidx]];
        if(mid>left)//elements exists
            root->left= split_tree(preorder,inoidxmp,rootidx+1,left,mid-1);
        if(right>mid)
            root->right= split_tree(preorder,inoidxmp,rootidx+mid-left+1,mid+1,right);//mid-left+1 calculates the number of element in left subtree

        return root;
    }
};
