
//Check from right to left if you found any value smaller than any value in right 
//if No that mean its max value possible so reverse that mean first value of permutation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int max = nums[n-1],idx = -1;
        for(int i = n-2;i>=0;i--){
            if(max > nums[i]){
                idx = i;
                break;
            }
            max = nums[i];
        }
        if(idx == -1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int minidx = idx+1;
        for(int i = idx+1;i<n;i++)
        {
            if(nums[i]>nums[idx] && nums[minidx]>=nums[i])
            {
                minidx = i;
            }
        }
        swap(nums[idx],nums[minidx]);
        reverse(nums.begin()+idx+1,nums.end());
    }
};