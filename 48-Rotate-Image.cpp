// A Very good logic 
// Vertical Reversal of matrix (Flip along the horizontal axis) like first row to last row and second to second last
// Than Transpose of matrix (Swap rows and columns) diagonally exchange element

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        for(int i = 0;i<n/2;i++){
            for(int j = 0;j<n;j++){
                swap(matrix[i][j], matrix[n-i-1][j]);
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};