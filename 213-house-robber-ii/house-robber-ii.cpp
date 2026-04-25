class Solution {
    int solve2(int idx , vector<int>&nums,vector<int>& dp){
        if(idx <= 0)return 0;
        if(idx == 1)return nums[1];
        if(idx == 2)return  max(nums[1],nums[2]);
        if(dp[idx] != -1)return dp[idx];

        return dp[idx] = max(solve2(idx-1,nums,dp),solve2(idx-2,nums,dp) + nums[idx]);
    }
    
    int solve1(int idx , vector<int>& nums, vector<int>&dp){
        if(idx == 0)return nums[0];
        if(idx == 1)return max(nums[0],nums[1]);
          if(dp[idx] != -1)return dp[idx];
        return dp[idx] = max(solve1(idx-1,nums,dp), solve1(idx-2,nums,dp) + nums[idx]);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size()-1;
        if(n==0)return nums[0];
        if(n==1)return max(nums[0],nums[1]);
        vector<int>dp1(n+1,-1);
        int rob1 = solve1(n-1,nums,dp1);
         vector<int>dp2(n+1,-1);
        int rob2 = solve2(n,nums,dp2);

        return max(rob1, rob2);
    }
};