class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int k=0;
        for(int b=n/2;b>=1;b/=2)
            while(k+b<n && nums[k+b]<=target) k+=b;
        
        if (nums[k]==target) return k;
        return -1;
    }
};
/*For k + b to exceed or equal n:

k would already need to be close to the end of the array.
The step size b would need to be large enough to push k out of bounds.
*/