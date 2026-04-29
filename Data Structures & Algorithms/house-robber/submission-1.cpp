class Solution {
public:
    int rob(vector<int>& nums) {
       return robHelper(nums,0);
    }
    unordered_map<int,int> memo;
    int robHelper(vector<int>& nums,int i){
        if(memo.count(i)) return memo[i];
        if(i>=nums.size()) return 0;

      
      return memo[i]= max(nums[i] + robHelper(nums, i + 2), robHelper(nums, i + 1));
    }
};
