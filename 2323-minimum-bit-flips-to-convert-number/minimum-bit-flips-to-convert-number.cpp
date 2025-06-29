class Solution {
public:
    int minBitFlips(int start, int goal) {
        if(start==goal)return 0;

        int ans = start^goal;
        int cnt=0;
        for(int i = 0 ; i < 31; i++){
            if(ans&(1<<i))cnt++;
        }
        return cnt;
    }
};