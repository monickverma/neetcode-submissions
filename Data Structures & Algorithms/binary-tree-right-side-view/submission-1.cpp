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
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
         vector<vector<int>> res;
        if(!root) return result;

        queue<TreeNode*> q;
         
        q.push(root);
        
        while(!q.empty()){
            vector<int> level;
            int size=q.size();
            
            for(int i=q.size();i>0;i--){
            TreeNode* current= q.front();
            q.pop();
            if(current){
                level.push_back(current->val);
           q.push(current->left);
            q.push(current->right);
            }
            }
            if(!level.empty()) res.push_back(level);
        }
            
        for(int i=0;i<res.size();i++){
            int x=res[i].back();
            result.push_back(x);

        }
        return result;
    }
};
