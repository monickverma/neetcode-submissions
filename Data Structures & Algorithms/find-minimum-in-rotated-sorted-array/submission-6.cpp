class Solution {
   public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        
        while (true) {
            int mid = l + (r - l) / 2;
            if (nums[l] > nums[r]) {
                // check for subparts

                if (nums[l] > nums[mid])  // minimum here
                    r = mid;
                else  // minimum here
                    l = mid + 1;
            } else
                return nums[l];
        }
    }
};
