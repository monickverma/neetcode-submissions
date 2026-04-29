class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> subsets;
    vector<int> current;
    generate_subsets(nums, current, 0, subsets);
        return subsets;
        
    }

    void generate_subsets(vector<int>& nums, vector<int>& current, int index, vector<vector<int>>& result) {
    if (index == nums.size()) { 
        result.push_back(current);
        return;
    }
    generate_subsets(nums, current, index + 1, result);

     current.push_back(nums[index]);
    generate_subsets(nums, current, index + 1, result);
    
    
    current.pop_back();
}
};
