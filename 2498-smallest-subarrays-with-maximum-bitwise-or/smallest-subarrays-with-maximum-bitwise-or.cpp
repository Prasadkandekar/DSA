class Solution {
public:

    vector<int> smallestSubarrays(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>ans(n);
        vector<int> lastPos(32,-1);

        for(int i = n-1 ; i >= 0 ;i--){
            for(int b = 0 ;b < 32 ;b++){
                if((nums[i]>>b)&1){
                    lastPos[b] = i;
                }
            }
        

        int maxReach = i;
        for(int b = 0 ;b < 32 ;b++){
            if(lastPos[b] != -1){
                maxReach = max(maxReach,lastPos[b]);
            }
        }
            ans[i] = maxReach-i+1;
        }
      
        return ans;
    }
};

//Brute force : TLE
// class Solution {
// public:

//     vector<int> smallestSubarrays(vector<int>& nums) {
        
//         int n = nums.size();
//         vector<int>ans(n);
      
//         for(int i = 0 ;i < n ; i++){
//             int maxOr = 0;
//             for(int j = i ; j< n;j++){
//                 maxOr |= nums[j];
//             }
//             int cnt = 0;
//             int currOr= 0;
//             for(int j= i ;j < n ;j++){
                
//                 currOr |= nums[j];
//                 cnt++;
//                 if(currOr==maxOr){     
//                     break;
//                 }
                
//             }
//             ans[i] = cnt;
//         }
//         return ans;
//     }
// };