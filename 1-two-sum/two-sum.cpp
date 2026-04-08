class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0 ;i < n; i++){
            int reqd = target - nums[i];
            if(mp.find(reqd) != mp.end()){
                return {mp[reqd],i};
            }

            mp[nums[i]] = i;
        }
        return {-1,-1};
    }
};