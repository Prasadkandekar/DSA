class Solution {
public:
    int minPartitions(string num) {
        int maxi = -1;
        int n = num.size();
        for(int i =0 ;i < n ; i++){

            maxi = max(maxi,num[i]-'0');
        }
        return maxi;
    }
};