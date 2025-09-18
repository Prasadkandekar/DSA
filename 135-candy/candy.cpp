class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>left(n,0);
        vector<int>right(n,0);

        left[0] = 1;
        right[n-1] = 1;

        for(int i = 1 ; i< n ;i++){
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1]+1;
            }else{
                left[i] = 1;
            }
        }

        for(int j = n-2 ;j >=0;j--){
            if(ratings[j] > ratings[j+1]){
                right[j] = right[j+1]+1;
                
            }else{
                right[j] = 1;

            }
        }

        int minCandies = 0;
        for(int i = 0 ;i < n ;i++){
            minCandies += max(left[i],right[i]);
        }

        return minCandies;
    }
};