class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
        }else if(target < 0){
            return ;
        }
        for(int i = idx;i<candidates.size(); i++){
            if(target < candidates[i])
                break;
            target = target-candidates[i];
            temp.push_back(candidates[i]);
            combinsum(candidates,result,target,temp,i);
            target += candidates[i];
            temp.pop_back();
        }
    }
};