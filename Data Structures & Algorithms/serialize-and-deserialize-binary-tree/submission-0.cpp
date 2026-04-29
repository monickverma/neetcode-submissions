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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if(!root) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        istringstream ss(data);
        return deserializeHelper(ss);
        
    }

     TreeNode* deserializeHelper(istringstream& ss){
        string val;
        getline(ss,val, ',');

        if(val=="#")return nullptr;

        TreeNode* root=new TreeNode(stoi(val));
        root->left=deserializeHelper(ss);
        root->right=deserializeHelper(ss);
        return root;
     }
};
