class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        sort(nums.begin(), nums.end());
        bool hasPositive = false;
        int ans =0;
        int maxi = nums[0];
        if(nums[0] > 0){
            ans += nums[0];
            hasPositive = true;
        }
        for(int i = 1;i < n ;i++){
           if( nums[i] >0 && nums[i] != nums[i-1]){
           ans += nums[i];
            hasPositive = true;
           }
        }

        if (!hasPositive) return *max_element(nums.begin(), nums.end());
        
        return ans;
    }
};