class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int>mpp;
        vector<int>lucky;
        for(int i = 0 ;i < arr.size() ;i++){
            mpp[arr[i]]++;
        }
        for(auto it : mpp){
            if(it.first==it.second)lucky.push_back(it.first);
        }

        return (lucky.size() >0)?lucky[lucky.size()-1]:-1;

    }
};