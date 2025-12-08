class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;

        for(int i = 1 ; i <= n;i++){
            for(int j = 1 ; j <= n ; j++){
                int sum = i*i + j*j;
             int   k = sqrt(sum);
                if( k*k==sum && k <= n){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};