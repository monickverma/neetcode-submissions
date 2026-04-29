/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid,0,0,grid.size());
    }

    Node* build(vector<vector<int>>& grid,int r,int c,int size){
        int same=1;
        int first= grid[r][c];

        for(int i=r; i<r+size; i++)
                for(int j=c; j<c+size; j++)

                if(grid[i][j] != first){
                    same=0;
                    break;
                }
        
        if(same) return new Node(first,1);

         size=size/2;

        Node* topLeft = build(grid, r, c,size);
        Node* topRight = build(grid, r, c + size,size);
        Node* bottomLeft = build(grid, r +size,c,size);
        Node* bottomRight = build(grid, r +size, c + size,size);
            
        return new Node(0,0,topLeft, topRight, bottomLeft, bottomRight);
    }
};