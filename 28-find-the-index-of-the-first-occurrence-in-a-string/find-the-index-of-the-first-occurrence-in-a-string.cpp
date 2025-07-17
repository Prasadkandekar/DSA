class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();

        if(n==0)return 0;

        for(int i =0 ;i < m-n+1;i++){
            int match = 1;
            for(int j = 0 ;j < n ;j++){
                if(haystack[i+j] != needle[j]){
                    match = 0;
                    break;
                }
            
            }
            if(match ==1)return i;
        }


        return -1;
    }
};