class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low=0,high=nums.size();

        while(low<high){
            int mid= low+ (high-low)/2;
            if(nums[mid]>target)high=mid;
            else low=mid+1;

        }
        return (low>0 && nums[low-1]==target)?low-1:-1;
        
    }
};
