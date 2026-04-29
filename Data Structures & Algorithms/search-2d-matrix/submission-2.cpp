class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix[0].size();

        for(int i=0;i<matrix.size();i++){
            int k=0;
        for(int b=n/2;b>=1;b/=2){
            while(k+b<n && matrix[i][k+b]<=target) k+=b;
        }
            if(matrix[i][k]==target) return true;//target mil gya then ok else continue with the loop
        }
        return false;
    }
};
