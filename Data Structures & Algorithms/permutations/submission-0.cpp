class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> res;

        dfs(nums, 0,res);

        return res;
    }

    void dfs(vector<int>& nums,int index, vector<vector<int>>& res){
        if(index==nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            dfs(nums,index+1,res);
            swap(nums[index],nums[i]);
        }
    }
};
