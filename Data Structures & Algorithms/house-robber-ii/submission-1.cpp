class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
       return max(robHelper(nums,0),robHelper2(nums,1));
    }
    unordered_map<int,int> memo;
    int robHelper(vector<int>& nums,int i){
        if(memo.count(i)) return memo[i];
        if(i>=nums.size()-1) return 0;

      
      return memo[i]= max(nums[i] + robHelper(nums, i + 2), robHelper(nums, i + 1));
    }
    
    unordered_map<int,int> memo2;
    int robHelper2(vector<int>& nums,int i){
        if(memo2.count(i)) return memo2[i];
        if(i>=nums.size()) return 0;

      
      return memo2[i]= max(nums[i] + robHelper2(nums, i + 2), robHelper2(nums, i + 1));
    }
};
