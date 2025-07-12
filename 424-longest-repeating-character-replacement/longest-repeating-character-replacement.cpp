class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int right = 0;
        vector<int>occ(26,0);
        int maxOccurance = 0;
        int ans =0;

        for(right ; right <s.size(); right++){
            occ[s[right]-'A']++;
            maxOccurance = max(maxOccurance , occ[s[right]-'A']);
            if((right-left+1)-maxOccurance >k){
                occ[s[left]-'A']--;
                left++;
            }
            ans = max(ans,right-left+1);

        }
        return ans;
    }
};