//getting cumulative sum of prefix 
// count how many time cumsum comes , 0 will be bydefault 1
//test case good to understand 
// [-2,-1,4,2]
//k = 4
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<int,int>mp;
      int result = 0;
      int cumsum = 0;
      mp.insert({0,1});

      for(int i=0;i<nums.size();i++){
        cumsum += nums[i];
        if(mp.find(cumsum-k) != mp.end()){
            result += mp[cumsum-k];
        }
        mp[cumsum]++;
      }  
    return result;
    }
};