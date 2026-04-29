class Solution {
public:
    unordered_map<string, bool> memo;

    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) return true;
        if (memo.count(s)) return memo[s];

        for (string word : wordDict) {
            if (s.find(word) == 0) { 
                if (wordBreak(s.substr(word.size()), wordDict)) {
                    return memo[s] = true;
                }
            }
        }

        return memo[s] = false;
    }
};
