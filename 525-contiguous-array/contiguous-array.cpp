class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxlength = 0;
        int prefixSum = 0;
        map<int,int>mp;
        mp[0]=-1;

        for(int i = 0 ; i< nums.size();i++){
            if(nums[i]==0)nums[i]= -1;
        }

        for(int i = 0 ;i < nums.size() ;i++){
            prefixSum += nums[i];
            if(mp.find(prefixSum) != mp.end()){
                maxlength = max(maxlength,i-mp[prefixSum]);
            }else{
                   mp[prefixSum]= i;
            }
        }
        return maxlength;
    }
};