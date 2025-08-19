class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        long long cnt = 0;
        int n  = nums.size();
        for(int i= 0 ;i < n; i++){
           if(nums[i]==0){
             long long zeroCnt = 0;

             while(i < n && nums[i] == 0){
                zeroCnt++;
                i++;
             }
             cnt += (zeroCnt*(zeroCnt + 1)/2);
           }
        }
        return cnt;
    } 
};