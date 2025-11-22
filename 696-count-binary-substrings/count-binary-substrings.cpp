class Solution {
public:
    int countBinarySubstrings(string s) {
        int n= s.size();
        int ans = 0 ;
        vector<int>grps;
        int cnt = 1;
        for(int i = 1 ;i < n;i++){
            if(s[i]==s[i-1]){
                cnt++;
            }else{
                grps.push_back(cnt);
                cnt = 1;
            }
        }
        grps.push_back(cnt);
        for(int i = 1 ;i< grps.size() ;i++){
            ans += min(grps[i],grps[i-1]);
        }
        return ans;
    }
};