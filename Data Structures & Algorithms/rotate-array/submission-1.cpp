class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        vector<int> copy=nums;

        for (int i = 0; i < n; i++) {
            copy[(i + k) % n] = nums[i];
        }

        nums = copy;
    }
};