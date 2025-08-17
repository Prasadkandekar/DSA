class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0)return 1.0;
        if(n >= k+maxPts-1)return 1.0;

        int size = k+maxPts;
        vector<double>dp(size,0.0);

        for(int x = k ;x <= n  && x < size ;x++){
            dp[x] = 1.0;
        }

        double window = 0.0;
        for(int j = k ;j < k+maxPts;j++){
            window += dp[j];
        }

        for(int i = k-1; i >=0 ;i--){
            dp[i] = window/maxPts;
            window = window -dp[i+maxPts]+dp[i];

        }
        return dp[0];
    }
};