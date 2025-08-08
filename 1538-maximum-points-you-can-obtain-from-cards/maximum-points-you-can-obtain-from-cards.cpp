class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int mxscore = 0;
        int rscore = 0;
        int lscore = 0;
        int n = cardPoints.size();

        for(int i = 0 ;i < k ; i++){
            lscore += cardPoints[i];
        }
        mxscore = lscore;

        for(int  i = 1 ;i <= k ; i++){
            lscore -= cardPoints[k-i];
            rscore += cardPoints[n-i];
            mxscore = max(mxscore , lscore+rscore);
        }


        return mxscore;
    }
};