class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int max_no=nums[0];
        int curr_max=1,curr_min=1;
        for(int num:nums){
            int temp=curr_max;
            curr_max=max(max(curr_max*num,curr_min*num),num);
            curr_min=min(min(temp*num,num*curr_min),num);
            max_no=max(max_no,curr_max);
        }
        return max_no;
        
    }
};
