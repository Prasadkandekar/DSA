class Solution {
public:
    int beautySum(string s) {
        int beauty = 0;
        for(int i = 0 ;i < s.size(); i++){
            vector<int>alphabets(26,0);
            

            for(int j = i ; j < s.size() ;j++){
                alphabets[s[j]-'a']++;
                int minf =INT_MAX;
                int maxf = 0;
                 for(int i = 0 ;i < 26 ;i++){
                if(alphabets[i] != 0 && alphabets[i] < minf)minf = alphabets[i];
                if(alphabets[i] > maxf)maxf = alphabets[i];
            }
             beauty += maxf-minf;
            }

           
           
           
        }
        return beauty;
    }
};