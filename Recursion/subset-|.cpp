class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        subset(nums,res,temp,0);
        return res;
    }

    void subset(vector<int>& nums, vector<vector<int>>& res, vector<int> temp, int k){
        if(k == nums.size()){
            res.push_back(temp);
            return;
        }
        subset(nums,res,temp,k+1);
        temp.push_back(nums[k]);
        subset(nums,res,temp,k+1);
    }



};