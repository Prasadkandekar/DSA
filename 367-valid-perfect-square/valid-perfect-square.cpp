class Solution {
public:
    bool isPerfectSquare(int num) {
        long left = 1 ;
        long right = num;

        while(left <= right){
            long long mid = (left + right)/2;
            long long sqr = mid*mid;
            if(sqr == num)return true;
            if(sqr < num)left = mid+1;
            if(sqr > num)right = mid-1;
        }

        return false;
    }
};