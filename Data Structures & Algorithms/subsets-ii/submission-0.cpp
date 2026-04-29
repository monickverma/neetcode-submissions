class Solution {
public:
   
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> subsets;
    vector<int> current;
    sort(nums.begin(),nums.end());
    generate_subsets(nums, current, 0, subsets);
        return subsets;
        
    }

    void generate_subsets(vector<int>& nums, vector<int>& current, int index, vector<vector<int>>& result) {
    if (index == nums.size()) { 
        result.push_back(current);
        return;
    }
    current.push_back(nums[index]);
    
    
    generate_subsets(nums, current, index + 1, result);
    
    current.pop_back();

    while(index+1<nums.size() && nums[index]==nums[index+1]) index++;
    
    generate_subsets(nums, current, index + 1, result);
}
};