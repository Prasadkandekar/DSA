class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        int prev1 = 0;
        int prev2 = 0;

        for(int i  = 0 ;i < n-1; i++){
            int curr_i = max(prev1,prev2+nums[i]);
            prev2 = prev1;
            prev1 = curr_i;
        }
        int rob1 = prev1;
        prev1 = prev2 = 0;
        for(int i = 1 ;i < n;i++){
            int curr_i = max(prev1,prev2+nums[i]);
            prev2 = prev1;
            prev1 = curr_i;
        }

        return max(rob1,prev1);
    }
};