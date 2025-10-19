class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        combinsum(candidates,res,target,temp,0);
        return res;

    }
    
    void combinsum(vector<int>& candidates, vector<vector<int>>& result ,int target,vector<int> temp,int idx){
        if(target == 0){
            result.push_back(temp);
            return;
        }else if(target < 0 || idx >= candidates.size()){
            return ;
        }
        if(target < candidates[idx])
            return;
        int val = candidates[idx];
        while(idx < candidates.size() && candidates[idx] == val){
            int j = idx;
            while(j < candidates.size() && candidates[j] == val)
                j++;
            combinsum(candidates,result,target,temp,j);
            temp.push_back(candidates[idx]);
            target -= candidates[idx];
            idx++;
        }
        combinsum(candidates,result,target,temp,idx);
    }
};