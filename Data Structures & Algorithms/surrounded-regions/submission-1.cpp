/*
only the O which are in border wil be not be surrounded by wate ron all
4 sides, when traversing using dfs it then is guranteed to answer all 
possiblities present
*/

class Solution {
public:

    void dfs(int row,int col, vector<vector<char>>& board){
        int m=board.size();
        int n=board[0].size();

        if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != 'O') 
            return;
        
        board[row][col]='#';

         vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto dir : directions) {
            dfs(row + dir.first, col + dir.second, board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        if(m==0) return;
        int n=board[0].size();

        for(int i=0;i<m;i++){ 
            if(board[i][0]=='O') dfs(i,0,board);
            if(board[i][n-1]=='O') dfs(i,n-1,board);
        }

        for(int j=0;j<n;j++){
            if(board[0][j]=='O')dfs(0,j,board);
            if(board[m-1][j]=='O')dfs(m-1,j,board);
        }


        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='#') board[i][j]='O';
            }
    }
};
