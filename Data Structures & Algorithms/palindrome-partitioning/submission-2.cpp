class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> current;
        vector<vector<string>> res;

        backtrack(0,s,current,res);
        return res;
    }

    void backtrack(int start, string&s, vector<string>& curr,vector<vector<string>>&res){
        if(start==s.size()) {res.push_back(curr);return;}

        for(int end=start;end<s.size();end++){
           if(isPalindrome(s,start,end)){ curr.push_back(s.substr(start,end-start+1));
            backtrack(end+1,s,curr,res);
            curr.pop_back();}
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
/*

make the tree!

start=0
├── choose "a"
│   start=1
│   ├── choose "a"
│   │   start=2
│   │   └── choose "b"
│   │       start=3 ✅ save
│   │
│   └── choose "ab" ❌
│
├── choose "aa"
│   start=2
│   └── choose "b"
│       start=3 ✅ save
│
└── choose "aab" ❌

*/