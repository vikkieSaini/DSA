//keep counter counter at least return 1 if element is more than half times
//

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int ele = -1,c = 0;
        for(int i = 0;i<nums.size();i++){
            if(ele == -1)
                ele = nums[i];
            
            if(ele != nums[i])
                c--;
            else 
                c++;
            if(c == 0)
                ele = -1;
        }
        return ele;
    }
};