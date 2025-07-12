class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string s=strs[0];
        string s1=strs[strs.size()-1];
        string ans="";
        for(int i=0;i<min(s.size(),s1.size());i++){
            if(s[i]==s1[i]) ans+=s[i];
            else break;
        }
        return ans;
    }
};