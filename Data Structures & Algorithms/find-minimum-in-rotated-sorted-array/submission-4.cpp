class Solution {
public:
    int findMin(vector<int>& nums) {

        int l = 0;
        int r = nums.size() - 1;

        while(true)
        {
            int mid = l + (r - l) / 2;

            if(r - l + 1 == 1)
                return nums[r];

            if(nums[l] > nums[r])
            {
                if(nums[l] > nums[mid])
                    r = mid;
                else
                    l = mid + 1;
            }
            else
                return nums[l];
        }
    }
};