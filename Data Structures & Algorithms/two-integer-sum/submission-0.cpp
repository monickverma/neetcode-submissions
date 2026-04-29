class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> s;

    for (int i = 0; i < nums.size(); i++)
    {
        int compliment = target - nums[i];
        // agar compliment map me h tho badhiya h ji guru
        if (s.find(compliment) != s.end())
            return {s[compliment], i};
        s[nums[i]] = i;
    }
    return {};
}

};
