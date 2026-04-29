class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        dfs(candidates, target, 0, current, result);
        return result;
    }

private:
    void dfs(vector<int>& candidates, int target, int index, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {  // Found a valid combination
            result.push_back(current);
            return;
        }
        
        if (target < 0) return;  // Exceeded target, stop exploring this path

        for (int i = index; i < candidates.size(); ++i) {
            current.push_back(candidates[i]);  // Choose the element
            dfs(candidates, target - candidates[i], i, current, result);  // Recur with the same element
            current.pop_back();  // Backtrack and try the next element
        }
    }
};
