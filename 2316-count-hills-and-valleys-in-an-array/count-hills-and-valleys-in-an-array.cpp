class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        stack<int>st;
        int hill = 0;
        int valley = 0;
        int prev = nums[0];
        int next =0;
        for(int i = 1 ;i < n-1;i++){
            int j = i+1;
            while(j < n && nums[i]==nums[j]){
            j++;
            
            }
            if(j != n)next = nums[j];
            if(nums[i] > prev && nums[i] > next)hill++;
            if(nums[i] < prev && nums[i] < next)valley++;
            if(nums[i] != prev)prev = nums[i]; 
        }
    
        ans =hill + valley;
        return ans;
    }
};