class Solution {
public:
    vector<vector<int>> memo;

    int uniquePaths(int m, int n) {
        memo.resize(m + 1, vector<int>(n + 1, -1));
        return dfs(m, n);
    }

    int dfs(int m,int n){
        if(m==0||n==0) return 0;
        if(m==1 && n==1) return 1;
         
        if(memo[m][n]!=-1) return memo[m][n];
        return memo[m][n]=dfs(m-1,n)+dfs(m,n-1);
    }
};
