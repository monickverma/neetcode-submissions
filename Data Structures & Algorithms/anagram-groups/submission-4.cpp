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
          /* # is necessary or the key can be obstructed as if
           there are multiples of a number for exam 10 b's 
           this will give me an error in the key as there is no sepreation */
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
