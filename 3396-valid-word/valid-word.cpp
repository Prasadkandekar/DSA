class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3)return false;
        bool hasVowel = false;
        bool hasConsonant = false;

        for(char c : word){

            if(isalpha(c)){
                char s = tolower(c);
                if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u'){
                    hasVowel = true;
                }else{
                    hasConsonant = true;
                }
            }else if(isdigit(c)){
                continue;
            }else{
                return false;
            }
        }
    return hasVowel && hasConsonant;
    }
};