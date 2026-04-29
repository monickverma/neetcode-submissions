class Solution {
     vector<vector<int>> dp;
    int totalSum;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        dp = vector<vector<int>>(nums.size(), vector<int>(2 * totalSum + 1, -1));
        return backtrack(0,0,nums,target);
        
    }

    int backtrack(int i, int res, vector<int>& nums,int target){
        if(i==nums.size()) return res==target;
        if (dp[i][res + totalSum] != -1) {
            return dp[i][res + totalSum];
        }

        return dp[i][res + totalSum]=  backtrack(i+1,res+nums[i],nums,target)+
                                         backtrack(i+1,res-nums[i],nums,target);
    }
};
