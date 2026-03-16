class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int>ransom_mp;
        map<char,int>magazine_mp;

        for(auto ch : ransomNote){
            ransom_mp[ch]++;
        }
        for(auto ch : magazine){
            magazine_mp[ch]++;
        }

       for(auto it = ransom_mp.begin();it != ransom_mp.end();){
         if(it->second <= magazine_mp[it->first]){
            it = ransom_mp.erase(it);
         }else{
            it++;
         }
       }

        if(ransom_mp.size()==0)return true;
        return false;
    }
};