class Solution {
public:
/*
    int solve(int idx, int prev, const vector<int>& nums) {
    if (idx == nums.size()) return 0;

    // Don't pick the current element
    int notPick = solve(idx + 1, prev, nums);

    // Pick the current element if it's greater than the previous picked element
    int pick = 0;
    if (prev == -1 || nums[idx] > nums[prev]) {
        pick = 1 + solve(idx + 1, idx, nums);
    }

    return max(pick, notPick);
}
*/

vector<vector<int>> memo;

int dp(int index, int prevIndex, vector<int>& nums) {
    if (index == nums.size()) return 0;

    if (memo[index][prevIndex + 1] != -1)
        return memo[index][prevIndex + 1];

    // Not take current number
    int notTake = dp(index + 1, prevIndex, nums);

    // Take current number if it's larger than previous
    int take = 0;
    if (prevIndex == -1 || nums[index] > nums[prevIndex])
        take = 1 + dp(index + 1, index, nums);

    return memo[index][prevIndex + 1] = max(take, notTake);
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    // Initialize memo with size [n][n+1] and fill with -1
    memo = vector<vector<int>>(n, vector<int>(n + 1, -1));
    return dp(0, -1, nums);
}
};
