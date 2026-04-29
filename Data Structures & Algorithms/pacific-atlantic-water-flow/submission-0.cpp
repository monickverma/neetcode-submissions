class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int m;
    int n;
    void dfs(int row, int col,vector<vector<bool>>& ocean,vector<vector<int>>& heights) {
        ocean[row][col]=true;

        for(auto dir:directions){
            int newR=row+dir.first, newC=col+dir.second;

            if(newR>=0 && newR<m && newC>=0 && newC<n && !ocean[newR][newC] && heights[newR][newC]>=heights[row][col])
                dfs(newR,newC,ocean,heights);
        }


    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty()) return {};
        vector<vector<int>> res;
         m=heights.size();
         n=heights[0].size();

        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));

        for(int i=0;i<m;i++) dfs(i,0,pacific,heights);
        for(int j=0;j<n;j++) dfs(0,j,pacific,heights);

        for(int i=0;i<m;i++) dfs(i,n-1,atlantic,heights);
        for(int j=0;j<n;j++) dfs(m-1,j,atlantic,heights);

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(pacific[i][j] && atlantic[i][j]) 
                    res.push_back({i,j});
        return res;
        
    }
};
