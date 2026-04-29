class Solution {
public:
    
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> count;
    for (auto num : nums)
    {
        count[num]++;
    }

    vector<vector<int>> freq(nums.size() + 1);

    for (auto x : count)
    {
        freq[x.second].push_back(x.first);
    }

    vector<int> res;
    for (int i = freq.size() - 1; i > 0; i--)
    {
        for (auto n : freq[i])
        {
            res.push_back(n);
            if (res.size() == k)
                return res;
        }
    }
    return res;
}
};
