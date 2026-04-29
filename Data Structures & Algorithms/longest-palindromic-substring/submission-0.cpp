class Solution {
public:
 vector<vector<int>> memo;

    bool isPalindrome(const string& s, int l, int r) {
        if (l >= r) return true;
        if (memo[l][r] != -1) return memo[l][r];
        if (s[l] != s[r]) return memo[l][r] = 0;
        return memo[l][r] = isPalindrome(s, l + 1, r - 1);
    }
    string longestPalindrome(string s) {
        int n=s.size();
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        int resLen=0;
        string res="";

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)&&(j-i+1>resLen)){
                    resLen=j-i+1;
                    res=s.substr(i,j-i+1);
                }
            }
        }
        return res;
        
    }
};
