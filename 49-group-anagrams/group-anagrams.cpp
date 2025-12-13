class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        int n = strs.size();

        map<string,vector<string>>mp;
        
        for(int i = 0 ;i < n ;i++){
            vector<int>cnt(26);
            for(char c: strs[i]){
                cnt[c-'a']++;
            }
            string key = "";
            for(int i= 0 ; i < 26 ; i++){
                key +='$';
                key += cnt[i]-'0';
            }
            // string key = strs[i];
            // sort(key.begin(),key.end());
            mp[key].push_back(strs[i]);
        };

        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};