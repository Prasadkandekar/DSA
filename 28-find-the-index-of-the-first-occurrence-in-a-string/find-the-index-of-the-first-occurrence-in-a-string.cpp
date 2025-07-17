class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size())return -1;
        int m = haystack.size();
        int n = needle.size();
        
        if(n==0)return 0;

        for(int i = 0 ;i < m-n+1 ;i++){
            bool match = true;
            for(int j = 0 ;j < n ;j++){
                if(haystack[i+j] != needle[j]){
                    match = false;
                    break;
                }
            }
            if(match == true)return i;
        }
        return -1;
    }
};