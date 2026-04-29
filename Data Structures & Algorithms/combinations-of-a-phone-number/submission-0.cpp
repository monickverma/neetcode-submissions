class Solution {
public:
    vector<string> res;
    vector<string> dtc{"", "", "abc", "def", "ghi", "jkl", 
                                  "mno", "qprs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        backtrack(0,"",digits);
        return res;
    }

    void backtrack(int i,string curstr, string &digits){
        if(curstr.size()==digits.size()) {
            res.push_back(curstr);
            return;
        }
        string chars=dtc[digits[i]-'0'];
        for(char c: chars)
            backtrack(i+1,curstr+c,digits);
    }
};
