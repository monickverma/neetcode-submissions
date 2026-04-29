class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         vector<set<char>> rows(9);
    vector<set<char>> cols(9);
    vector<set<char>> subgrids(9);
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char num = board[i][j];
            if (num == '.') continue;  // Skip empty cells

            // Check row i
            if (rows[i].count(num)) return false;
            rows[i].insert(num);

            // Check column j
            if (cols[j].count(num)) return false;
            cols[j].insert(num);

            // Check subgrid, index based on i and j
            int subgridIndex = (i / 3) * 3 + (j / 3);
            if (subgrids[subgridIndex].count(num)) return false;
            subgrids[subgridIndex].insert(num);
        }
    }
    
    return true;
    }
};
