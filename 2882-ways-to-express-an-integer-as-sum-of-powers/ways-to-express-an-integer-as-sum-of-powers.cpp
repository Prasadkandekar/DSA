class Solution {
public:
    const long long mod = 1e9+7;
    int t[301][301];
    long long modPow(long long base , long long expo, long long mod){
        long long ans = 1;
        base %= mod;
        while(expo){
            if(expo & 1) ans  = (ans*base)%mod;
            base = (base*base)%mod;
            expo = expo >> 1;
        }
        return ans;
    }
    long long solve(long long n , long long num ,long long x){
        if(n==0)return 1;
        if(n < 0 )return 0; 
        long long currPower = modPow(num,x , mod);
        if(currPower > n)return 0;
        if(t[n][num] != -1){
            return t[n][num];
        }
        long long take = solve(n-currPower,num+1,x);
        long long skip = solve(n,num+1,x);
        return t[n][num]=(take + skip)%mod;
    }
    int numberOfWays(int n, int x) {
        memset(t,-1,sizeof(t));
        return solve(n,1,x);
    }
};