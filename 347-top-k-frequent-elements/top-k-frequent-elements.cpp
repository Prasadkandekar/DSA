class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mp;
        vector<int>ans;

        for(int num : nums){
            mp[num]++;
        }
        while(k--){
            pair<int,int>maxiPair = {INT_MIN,INT_MIN};
            for(auto it : mp){
                if(it.second > maxiPair.second){
                   maxiPair.first = it.first;
                   maxiPair.second = it.second;

                }

            }
            ans.push_back(maxiPair.first);
            mp.erase(maxiPair.first);
            
        }
        return ans;
    }
};