class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int ans = 0;
        vector<int>arr(60);

        for(int i = 0 ;i < n ;i++){
           int rem = time[i]%60;
           int comp = (60-rem)%60;

           ans += arr[comp];
           arr[rem]++;
        }

        
        return ans;
    }
};