class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0) return;
        int n=grid[0].size();

        queue<pair<int,int>> q;
        vector<pair<int,int>> directions {{1,0},{-1,0},{0,1},{0,-1}};

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==0)
                    q.push({i,j});
        

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(auto dir:directions){
                int newX=x+dir.first;
                int newY=y+dir.second;

                if(newX>=0 && newX<m && newY>=0 && newY<n && grid[newX][newY]==INT_MAX){
                    grid[newX][newY]=grid[x][y]+1;
                    q.push({newX,newY});}

            }
        }
        
    }
};
