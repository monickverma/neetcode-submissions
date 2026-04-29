class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     unordered_map<string, vector<string>> m;
    for (int i = 0; i < strs.size(); i++)
    {
        string sortedStr = strs[i];
        sort(sortedStr.begin(), sortedStr.end());
        m[sortedStr].push_back(strs[i]);
    }
    vector<vector<string>> result;
    for (auto group : m)
        result.push_back(group.second);
    return result;
    }
};
