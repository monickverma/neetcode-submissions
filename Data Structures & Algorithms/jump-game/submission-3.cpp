class Solution {
public:
    vector<int> dp;
    bool canJump(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return dfs(0,nums);
    }
    bool dfs(int start,vector<int>&nums){
        if(dp[start]!=-1) return dp[start];
        if(start>=nums.size()-1) return true;

        for(int jump=1;jump<=nums[start];jump++)
            {if(dfs(start+jump,nums))return dp[start]=true;}
        return dp[start]=false;
    }
};
