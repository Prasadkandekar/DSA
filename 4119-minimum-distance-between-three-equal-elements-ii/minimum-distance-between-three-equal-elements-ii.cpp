class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        map<int,vector<int>>mp;

        for(int i = 0 ;i < n ;i++){
            mp[nums[i]].push_back(i);

        }

        int dist = INT_MAX;
   
        for(auto &it : mp){
            auto &v = it.second;
            int sz = v.size();
            for(int l = 0 ; l+2 < sz ; l++){
                int i = v[l];
                int j = v[l+1];
                int k = v[l+2];
                int new_dist = abs(i-j) + abs(j-k) + abs(k-i);
                dist = min(dist,new_dist);
            }
        }
        return (dist == INT_MAX)?-1 : dist;
    }
};