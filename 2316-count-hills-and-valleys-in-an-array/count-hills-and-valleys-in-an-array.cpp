class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int>clean;
        int n = nums.size();
        int ans = 0;
        
        for(int i = 0 ;i < n ;i++){
            if(i==0 || nums[i] != nums[i-1])clean.push_back(nums[i]);
        }

        for(int i = 1 ;i < clean.size()-1 ;i++){
            if(clean[i] > clean[i-1] && clean[i] > clean[i+1])ans++;
            else if(clean[i] < clean[i-1] && clean[i] < clean[i+1])ans++;
        }
        return ans;
    }
};