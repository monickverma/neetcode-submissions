class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int currSum=0;
        int res=INT_MAX;
        for(int r=0;r<nums.size();r++){

            currSum+=nums[r];
            while(currSum-target>=0){
                res=min(r-l+1,res);
                currSum-=nums[l];
                l++;
            }
            


            
        }

        return res==INT_MAX?0:res;
        
    }
};