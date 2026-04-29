class Solution {
public:
    vector<vector<string>> partition(string s) {

        vector<vector<string>> res;
        vector<string> current;
        dfs(s, current, 0, res);
    
       
        return res;
    }

    void dfs(string &s, vector<string> &curr, int start, vector<vector<string>> &res) {
        if (start == s.size()) { 
            res.push_back(curr);
            return;
        }

        for(int end=start;end<s.size();end++){
            if(isPalindrome(s,start,end)){
                curr.push_back(s.substr(start,end-start+1));
                dfs(s,curr,end+1,res);
                curr.pop_back();
            }
        }
        
    }

    bool isPalindrome(string &s,int left,int right) {
        if(s.empty()) return false;
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};
