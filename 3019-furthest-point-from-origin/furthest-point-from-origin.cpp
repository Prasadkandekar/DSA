class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int left =0 ;
        int right = 0;
        for(int i = 0 ; i < n ; i++){
            if(moves[i]=='L'){
                left++;
                right--;
            }else if(moves[i]== 'R'){
                right++;
                left--;
            }else{
                left++;
                right++;
            }
        }

        return max(left,right);
    }
};