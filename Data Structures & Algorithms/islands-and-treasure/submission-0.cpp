class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty()) return;

        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; ++i) 
            for (int j = 0; j < cols; ++j) 
                if (grid[i][j] == 0)  
                    dfs(grid, i, j, 0);

    }
    void dfs(vector<vector<int>>& rooms, int i, int j, int distance) {
        int rows = rooms.size();
        int cols = rooms[0].size();

        if (i < 0 || i >= rows || j < 0 || j >= cols || rooms[i][j] < distance) 
            return;
        

        rooms[i][j] = distance;

        dfs(rooms, i + 1, j, distance + 1); 
        dfs(rooms, i - 1, j, distance + 1); 
        dfs(rooms, i, j + 1, distance + 1); 
        dfs(rooms, i, j - 1, distance + 1); 
    }
};