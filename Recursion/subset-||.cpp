class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        subset(nums,res,temp,0);
        return res;
    }

    void subset(vector<int>& nums, vector<vector<int>>& res, vector<int> temp, int k){
        if(k == nums.size()){
            res.push_back(temp);
            return;
        }
        int val = nums[k];
        while(k < nums.size() && nums[k] == val){
            int j = k;
            while(j<nums.size() && nums[j] == val)
                j++;
            //if(j != nums.size())
            subset(nums,res,temp,j);
            temp.push_back(nums[k]);
            k++;
        }
        subset(nums,res,temp,k);
    }
};