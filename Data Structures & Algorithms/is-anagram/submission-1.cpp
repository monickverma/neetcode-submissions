class Solution {
public:
    bool isAnagram(string s, string t) {
          if (s.length() != t.length())
        return false;

    unordered_map<char, int> sC;
    unordered_map<char, int> tC;

    for (int i = 0; i < s.length(); i++)
    {
        sC[s[i]]++;
        tC[t[i]]++;
    }

    for (int i = 0; i < sC.size(); i++)
        if (sC[i] != tC[i])
            return false;
    return true;
    }
};