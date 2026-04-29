
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentSubset;
        backtrack(nums, 0, currentSubset, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<int>& currentSubset, vector<vector<int>>& result) {
        result.push_back(currentSubset);  // Store the current subset
        
        for (int i = start; i < nums.size(); ++i) {
            currentSubset.push_back(nums[i]);      // Choose
            backtrack(nums, i + 1, currentSubset, result);  // Recurse
            currentSubset.pop_back();              // Backtrack
        }
    }
};