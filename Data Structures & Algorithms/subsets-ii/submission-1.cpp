
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        vector<vector<int>> result;
        vector<int> currentSubset;
        backtrack(nums, 0, currentSubset, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<int>& currentSubset, vector<vector<int>>& result) {
        result.push_back(currentSubset);  // Include the current subset

        for (int i = start; i < nums.size(); ++i) {
            // Skip duplicates
            if (i > start && nums[i] == nums[i - 1]) continue;

            currentSubset.push_back(nums[i]);  // Include the current number
            backtrack(nums, i + 1, currentSubset, result);  // Recur with the next index
            currentSubset.pop_back();  // Remove the last added number to backtrack
        }
    }
};
/*
| Call Level   | start | i Value | currentSubset | result (Accumulated Subsets)      | Comment                             |
|------------  |-------|---------|---------------|-----------------------------------|-------------------------------------|
| 0            | 0     | 0       | []            | [[]]                              | Adding empty subset.                |
| 1            | 0     | 0       | [1]           | [[], [1]]                         | Include 1.                          |
| 2            | 1     | 1       | [1, 2]        | [[], [1], [1, 2]]                 | Include 2.                          |
| 3            | 2     | 2       | [1, 2, 2]     | [[], [1], [1, 2], [1, 2, 2]]      | Include 2 (duplicate allowed).      |
| 3(backtrack) | 2     | 2       | [1, 2]        | No change.                        | Backtracking - Removing last 2.     |
| 2(backtrack) | 1     | 1       | [1]           | No change.                        | Backtracking - Removing last 2.     |
| 2            | 1     | 2       | [1]           | No change.                        | Duplicate detected, skip 2.         |
| 1 (backtrack)| 0     | 0       | []            | No change.                        | Backtracking - Removing 1.          |
| 1            | 0     | 1       | [2]           | [[], [1], [1, 2], [1, 2, 2], [2]] | Include 2.                          |
| 2            | 1     | 2       | [2, 2]        | [[], [1], [1, 2], [1, 2, 2], [2], [2, 2]] | Include 2(duplicate allowed)|
| 2 (backtrack)| 1     | 2       | [2]           | No change.                        | Backtracking - Removing last 2.     |
| 1 (backtrack)| 0     | 1       | []            | No change.                        | Backtracking - Removing 2.          |
*/