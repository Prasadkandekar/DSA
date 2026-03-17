class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans;
        map<int,int>mp;
        for(auto num : arr1){
            mp[num]++;
        }

        int n = arr2.size();
        for(int i = 0 ;i < n  ; i++ ){

            while(mp[arr2[i]]--){
                ans.push_back(arr2[i]);
            }
            mp.erase(arr2[i]);

        }

        for(auto it : mp){
            
            while(it.second--){
                ans.push_back(it.first);
            }
        }


        return ans;
    }
};