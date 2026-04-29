class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum=0;
        int max_no=nums[0];
        for(int i=0;i<nums.size();i++){
            curr_sum=max(nums[i],curr_sum+nums[i]);
            max_no=max(curr_sum,max_no);
        }
        return max_no;

    }
};
