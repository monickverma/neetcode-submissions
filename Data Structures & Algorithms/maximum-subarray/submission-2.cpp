class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum=0;
        int max_sum=nums[0];
        for(int num:nums){
            curr_sum=max(num,curr_sum+num);
            max_sum=max(curr_sum,max_sum);
        }
        return max_sum;
    }
};
