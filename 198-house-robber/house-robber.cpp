class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();vector<int>dp(n,0);
        dp[0] = nums[0]; 
        if(n > 1)
        dp[1] = max(nums[0],nums[1]);
        for(int i = 2 ; i < n ;i++)dp[i] = max(dp[i-1],dp[i-2] + nums[i]);
        return dp[n-1];
    }
};

// dp --> memozation : passed
// class Solution {
// private:
//     int solve(int idx , vector<int>&nums,vector<int>&dp){
//         int n = nums.size();
//         if(idx == 0)return nums[0];
//         if(idx == 1)return max(nums[0],nums[1]);
//         if(dp[idx] != -1) return dp[idx];
//         return dp[idx] = max(solve(idx-1,nums,dp), solve(idx-2, nums,dp) + nums[idx]);
//     }
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>dp(n,-1);
//         return solve(n-1,nums,dp);
//     }
// };