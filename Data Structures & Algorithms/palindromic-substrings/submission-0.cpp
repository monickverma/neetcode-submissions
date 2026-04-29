class Solution {
public:

 vector<vector<int>> memo;
 bool isPalindrome(const string& s, int l, int r) {
        if (l >= r) return true;
        if (memo[l][r] != -1) return memo[l][r];
        if (s[l] != s[r]) return memo[l][r] = 0;
        return memo[l][r] = isPalindrome(s, l + 1, r - 1);
    }
    int countSubstrings(string s) {
         int n=s.size();
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){
                   ans++; 
                }
            }
        }
        return ans;
        
    }
};