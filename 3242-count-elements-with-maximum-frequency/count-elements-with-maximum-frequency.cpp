class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;
        for(auto num : nums){
            mp[num]++;
        }
        int maxi = 0;
        for(auto it : mp){
            
            maxi = max(maxi,it.second);
        }
        int cnt = 0;
        for(auto it : mp){
            if(it.second == maxi){
                cnt += maxi;
            }
        }
    return cnt;
    }
};