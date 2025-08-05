class Solution {
public:
    int lessThanOrEqualTo(vector<int>&nums,int goal){
        if(goal < 0)return 0;
        int n = nums.size();
        int sum = 0;
        int cnt = 0;
        int l = 0;
        int r = 0;
        while(r < n ){
            sum += nums[r];
            while(sum > goal){
                sum -=nums[l];
                l++;
            }
            cnt += r-l+1;//lenght;
            r++;
        }   
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return lessThanOrEqualTo(nums,goal)-lessThanOrEqualTo(nums,goal-1);
    }
};