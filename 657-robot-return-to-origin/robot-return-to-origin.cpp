class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        int RLcnt = 0;
        int UDcnt = 0;

        for(int i = 0 ;i < n ;i++){
            if(moves[i]=='U')UDcnt++;
            if(moves[i]=='R')RLcnt++;
            if(moves[i]=='D')UDcnt--;
            if(moves[i]=='L')RLcnt--;
        }
        return RLcnt == 0 && UDcnt == 0 ;
    }
};