class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor)return 1;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
          if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;


        bool sign = (dividend > 0) == (divisor > 0);
        
        long numerator = abs((long)dividend);
        long denominator = abs((long)divisor);
        long quotient = 0;
        
        while(numerator >= denominator){
            int cnt = 0;

            while(numerator >= (denominator<<(cnt+1))){
                 cnt++;
            }

            quotient += 1<<cnt;
            
            numerator -= (denominator<<cnt);

        }
        quotient = (sign)?quotient:-quotient;

        return(quotient > INT_MAX) ? INT_MAX : (quotient < INT_MIN) ? INT_MIN : quotient;
    }
};