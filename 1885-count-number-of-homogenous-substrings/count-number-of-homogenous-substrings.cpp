class Solution {
public:
    int countHomogenous(string s) {
        const long long mod = 1e9 + 7;
        long long ans = 0;
        int n  = s.size();
        for(int  i = 0;i < n ;i++){
          long long cnt = 1;
          int j = i+1;
          while(j<n && s[i]==s[j]){
            cnt++;
            j++;
          }
          ans  = (ans+ ((cnt*(cnt+1))/2)%mod)%mod;
          i = j-1;
        }
        return ans;
    }
};