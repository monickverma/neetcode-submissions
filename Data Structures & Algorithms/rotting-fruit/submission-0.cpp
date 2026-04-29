class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();

        queue<pair<int,int>> q;
        int freshfruitcount=0;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    freshfruitcount++;
            }
        int time=0;
            while(!q.empty()&& freshfruitcount>0){
                int size=q.size();
                time++;
            for(int i=0;i<size;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(auto dir:directions){
                    int newX=x+dir.first;
                    int newY=y+dir.second;

                    if(newX>=0 && newX<m && newY>=0 && newY<n && grid[newX][newY]==1){
                        grid[newX][newY]=2;
                        q.push({newX,newY});
                        freshfruitcount--;
                    }
                }

            }
                
            }
            if(freshfruitcount!=0)return -1;
        
            return time;

    }
};
