class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change5 = 0;
        int change10 = 0;
        int n = bills.size();

        for(int i = 0 ;i  < n ;i++){
            if(bills[i]==5)change5++;
            else if(bills[i]==10){
                change10++;
                if(change5 < 1)return false;
                change5--;
            }else{
                if(change10 >= 1 && change5 >= 1){
                    change10--;
                    change5--;
                }else if(change5 >= 3){
                    change5 -= 3;
                }else{
                    return false;
                }

                
            }
        }
        return true;
    }
};