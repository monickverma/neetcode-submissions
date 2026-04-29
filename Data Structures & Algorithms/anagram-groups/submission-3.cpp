class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     unordered_map<string, vector<string>> res;
    for (auto s : strs)
    {

        vector<int> chars(26, 0);

        for (char c : s)
        {
            chars[c - 'a']++;
        }

        // initialize key
        string key = to_string(chars[0]);
        for (int i = 1; i < 26; i++)
        {
            key += "#"+to_string(chars[i]);
        }
        res[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto pair : res)
    {
        result.push_back(pair.second);
    }
    return result;
    }
};
