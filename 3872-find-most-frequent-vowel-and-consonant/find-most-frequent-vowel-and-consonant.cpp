class Solution {
public:
    int maxFreqSum(string s) {
        // str = successes;
       vector<int>hashVowel(26,0);
       vector<int>hashConsonant(26,0);


       for(int i = 0 ;i < s.size() ;i++){
          if(s[i] == 'a' || s[i]== 'e' || s[i] == 'i'  || s[i] == 'o' || s[i] == 'u'){
                hashVowel[s[i] - 'a']++;
          }else{
            hashConsonant[s[i] - 'a']++;
          }
       }

    return *max_element(hashVowel.begin(),hashVowel.end()) + *max_element(hashConsonant.begin(),hashConsonant.end());

    }
};