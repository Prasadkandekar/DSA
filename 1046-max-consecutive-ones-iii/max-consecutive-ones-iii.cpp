class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxOnes = 0;
        int left ,right;
        left = right = 0;
        int zeros = 0;
        while(right < n){
           
            if(nums[right]==0)zeros++;
             int len = 0;
            if(zeros > k){   
                if(nums[left]==0)
                    zeros--;
                    left++;
            }
             if(zeros <= k)len= right-left+1;
            maxOnes = max(maxOnes,len);
             right++;
        }

        return maxOnes;
    }
};


//Brute Force : TLE
// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int n = nums.size();
//         int maxOnes = 0;
//         for(int i = 0 ;i< n ;i++){
//            int ones = 0;
//         int m = k;
//          for(int j = i ; j <  n ;j++){
               
//                 if(nums[j]==1)ones++;
//                 else if(m>0){
//                     ones++;
//                     m -=1;
//                 }else{
//                break;
//                 }
               
//             }
//              maxOnes = max(maxOnes,ones);
//         }
//         return maxOnes;
//     }
// };