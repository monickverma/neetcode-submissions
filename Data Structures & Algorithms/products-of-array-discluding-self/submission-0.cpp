class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums2) {

         vector<int> nums(nums2.size() + 2, 1);
     for (int i = 1; i < nums2.size()+1 ; i++)
    {
        nums[i] = nums2[i-1];
    }

    vector<int> res(nums.size() - 2, 1);
    int prefix = 1;
    for (int i = 1; i < nums.size() - 1; i++)
    {
        // prefix of num at i
        prefix *= nums[i - 1];
        res[i - 1] = prefix;
    }

    int postfix = 1;
    for (int i = nums.size() - 1; i > 1; i--)
    {
        postfix *= nums[i];
        // res[i]*=postfix;
        res[i - 2] *= postfix;
    }
    return res;
    }
};
