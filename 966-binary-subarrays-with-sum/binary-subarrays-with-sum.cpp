class Solution {
public:
    int atMost(vector<int>&nums ,int goal){
         if(goal < 0)return 0;
        int n = nums.size();
        int left,right;
        left = right = 0;
        int sum = 0;
        int cnt = 0;

        while(right < n){
            sum += nums[right];
           while(sum > goal){
            sum -= nums[left];;
            left = left+1;
           }
            cnt = cnt + (right-left+1);
            right++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       
       return atMost(nums,goal)-atMost(nums,goal-1);
    }
};


//Brute Force : 
// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int n = nums.size();
//         int ans = 0;
//         for(int i = 0 ;i <  n; i++){
//             int sum = 0;
//             for(int j = i ;j < n;j++){
//                 sum += nums[j];
//                  if(sum==goal)ans++;
//             }
           
//         }
//         return ans;
//     }
// };