class Solution {
public:
    
    int solveBottomLeft(int i , int j , vector<vector<int>>& dp1 ,vector<vector<int>>& fruits){
        int n = fruits.size();
        if(i==n-1 && j==n-1)return 0;
        if(j >= i)return 0;
        if(dp1[i][j] != -1)return dp1[i][j];

        int maxFruits = 0;
        int collectedFruits = fruits[i][j];
        if(i-1 >= 0) maxFruits = max(maxFruits,collectedFruits + solveBottomLeft(i-1,j+1,dp1,fruits));
        if(j+1 < n) maxFruits = max(maxFruits,collectedFruits + solveBottomLeft(i,j+1,dp1,fruits));
        if(i+1 < n )maxFruits = max(maxFruits , collectedFruits+solveBottomLeft(i+1,j+1,dp1,fruits));
        dp1[i][j] = maxFruits;
        return maxFruits;
    }
    int solveTopRight(int i , int j , vector<vector<int>>& dp2 ,vector<vector<int>>& fruits){
        int n = fruits.size();
        if(i==n-1 && j==n-1)return 0;
        if(i >= j)return 0;
        if(dp2[i][j] != -1)return dp2[i][j];
        
        int maxFruits = 0;
        int collectedFruits = fruits[i][j];
        if(j-1 >= 0)maxFruits = max(maxFruits,collectedFruits+solveTopRight(i+1,j-1,dp2,fruits));
        if(i+1 < n)maxFruits = max(maxFruits,collectedFruits + solveTopRight(i+1,j,dp2,fruits));
        if(j+1 < n)maxFruits = max(maxFruits,collectedFruits + solveTopRight(i+1,j+1,dp2,fruits));
            dp2[i][j] = maxFruits;
        return maxFruits;
    }
    int maxCollectedFruits(vector<vector<int>>& fruits) {
            int n = fruits.size();
    
    vector<vector<int>>dp1(n,vector<int>(n,-1));
    vector<vector<int>>dp2(n,vector<int>(n,-1));

    int totalFruits = 0;
    for(int i = 0 ;i < n ;i++){
        totalFruits += fruits[i][i];
    }

    totalFruits += solveBottomLeft(n-1,0,dp1,fruits);
    totalFruits += solveTopRight(0,n-1,dp2,fruits);
    return totalFruits;
    }
};