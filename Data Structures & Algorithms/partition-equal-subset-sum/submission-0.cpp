class Solution {
public:

    vector<vector<int>> memo;
    bool dfs(int idx,vector<int>& nums,int target){

        if(idx==nums.size()) return target==0;
        if(target<0) return false;
        if (memo[idx][target] != -1) {
            return memo[idx][target];
        }

        return memo[idx][target]=dfs(idx+1,nums,target-nums[idx])||dfs(idx+1,nums,target);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums)
            sum+=num;
        if(sum%2!=0) return false;
        memo=vector<vector<int>>(nums.size(),vector<int>(sum/2+1,-1));
        return dfs(0,nums,sum/2);
        
    }
};
