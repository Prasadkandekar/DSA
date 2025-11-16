class Solution {
public:
    int numSub(string s) {
        int n = s.size();
         const long long mod = 1000000007;
        long long ans = 0;
  
        for(int i = 0 ;i < n ;i++){
        while(s[i] != '1' && i < n){  
           i++;
        }
        int cnt = 0;
        if(s[i]=='1'){
            while(s[i]=='1'){
                cnt++;
                i++;
            }
        }
        // ans += (long long)(cnt*(cnt-1)/2)%mod;
     long long pairs = 1LL * cnt * (cnt + 1) / 2;
ans = (ans + pairs % mod) % mod;

    }

    return ans;
    }
   
};