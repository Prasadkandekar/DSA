class Solution {
public:
    bool hasAlternatingBits(int n) {
        int ones = 0;
        int zeros = 0;
        while(n>0){
            if(n & 1){
                if(zeros)zeros--;
                ones++;
            }
            else{
                if(ones)ones--;
                 zeros++;
            }
            n = n>>1;
            if(zeros == 2 || ones == 2)return false;
        }

        return true;;
    }
};