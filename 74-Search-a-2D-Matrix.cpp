//search in each column find out the row than do the binary search in that row 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m-1;
        while(l<r){
            int mid = (l+r)/2;
            if(matrix[mid][0] > target)
                r = mid;
            else if (matrix[mid][0] == target)
                return true;
            else
                l = mid;

            if(l+1 == r)
                break;
        }
        return binary_search(matrix[l].begin(),matrix[l].end(),target) || binary_search(matrix[r].begin(),matrix[r].end(),target);
    }
};