class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return true;
        if(n==1)return true;
        int maxReach = 0;
        int i;
        for( i  = 0 ;i <  n;i++){
            if(i > maxReach)return false;
            maxReach = max(maxReach, i+nums[i]);
        }
        return i-1 <= maxReach;
    }
};