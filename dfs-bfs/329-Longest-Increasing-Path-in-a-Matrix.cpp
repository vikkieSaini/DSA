
// simple logic of going all the direction and checking max value
// using dp for storing value at each index once traversed
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int maxx = 1;
        for(int i = 0;i<matrix.size(); i++) {
            for(int j = 0;j<matrix[0].size(); j++){
                int res = longestPath(matrix,dp,i,j,-1);
                maxx = max(maxx,res);
            }
        }
        return maxx;
    }

    int longestPath(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int val){

        if(i<0 || j<0 || i>= matrix.size() || j>=matrix[0].size() || val >= matrix[i][j])
            return 0;
        if(dp[i][j] > 1)
            return dp[i][j];
        int res = 1 + max(longestPath(matrix,dp,i+1,j,matrix[i][j]), max(longestPath(matrix,dp,i-1,j,matrix[i][j]),max(longestPath(matrix,dp,i,j-1,matrix[i][j]),longestPath(matrix,dp,i,j+1,matrix[i][j]))));
        dp[i][j] = res;
        return res;
    }
};