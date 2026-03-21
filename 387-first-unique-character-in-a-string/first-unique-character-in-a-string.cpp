class Solution {
public:
    int firstUniqChar(string s) {
       
        int n = s.size();

        int charFreq[26] = {0};

        for(int i = 0 ;i < n ;i++){
            charFreq[s[i]-'a']++;
            
        }

        for(int i=0 ;i < n  ; i++){
           if(charFreq[s[i]-'a'] ==1)return i;
        }
       return -1;
    }
};