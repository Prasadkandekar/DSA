class Solution {
public:
    const int mod = 1e9+7;
  
    
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>powers;
        for(int i = 0 ;i < 30 ;i++){
        if(n&(1<<i))  powers.push_back((1<<i));
        }
        vector<int>ans;
        int querySize = queries.size();
        for(int i = 0 ;  i < querySize ;i++){
               long long prod = 1;
            for(int j = queries[i][0] ; j <= queries[i][1] ; j++){
                    
                    prod = (prod*powers[j])%mod;
                    
            }
            ans.push_back((prod)%mod);
        }
        return ans;
    }
};