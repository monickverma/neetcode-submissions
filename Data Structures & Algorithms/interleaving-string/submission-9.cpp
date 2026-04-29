class Solution {
    vector<vector<int>> dp;
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size();
        int n=s2.size();
        if(m+n!=s3.size()) return false;
        dp=vector<vector<int>>(m+1,vector<int>(n+1,-1));
        return dfs(0,0,0,s1,s2,s3);
    }
bool dfs(int i,int j,int k, string& s1, string& s2, string& s3){
        if(k==s3.size()) return ((i==s1.size()) && (j==s2.size()));

        if(dp[i][j]!=-1) return dp[i][j];

        bool res=false;
        if(s1[i]==s3[k]&& i<s1.size()) {
            if(dfs(i+1,j,k+1,s1,s2,s3)) res= true;
        }
        
        if(s2[j]==s3[k]&& j<s2.size()) {
            if(dfs(i,j+1,k+1,s1,s2,s3)) res= true;
        }
        return dp[i][j]=res;
    }
};
