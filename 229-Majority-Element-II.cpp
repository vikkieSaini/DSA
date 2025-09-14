// same like majority element which is more than n/2 times
// here take two element bcoz max 2 value can be possible

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x = -1000000007, y = -1000000007,cx = 0,cy = 0,flag = 0;
        for(int i = 0;i<nums.size();i++){
            if(x == -1000000007 || x == nums[i])
                x = nums[i], cx++;
            else if(y == -1000000007 || y == nums[i])
                y = nums[i], cy++;
            else {
                if(cx == 0)
                    x = nums[i],cx++;
                else if(cy == 0)
                    y = nums[i],cy++;
                else 
                    cx--,cy--;
            }
        }
        cx = 0,cy = 0;
        for(int i = 0;i<nums.size();i++){
            if(x != -1000000007 && x == nums[i])
                cx++;
            else if(y != -1000000007 && y == nums[i])
                cy++;
        }
        vector<int> res;
        if(cx > nums.size()/3)
            res.push_back(x);
        if(cy > nums.size()/3)
            res.push_back(y);
        return res;
    }
};