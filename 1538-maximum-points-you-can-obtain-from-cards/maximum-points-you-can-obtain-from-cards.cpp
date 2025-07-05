class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int mxScore = 0;
        int lScore = 0,rScore = 0;

        for(int i = 0 ;i < k;i++)lScore += cardPoints[i];
        mxScore = lScore;


            for(int i =1;i <= k ;i++){
            lScore-= cardPoints[k-i];
            rScore += cardPoints[cardPoints.size() -i];
            
            mxScore = max(mxScore,lScore+rScore);
        }
     

        return mxScore;
    }
};