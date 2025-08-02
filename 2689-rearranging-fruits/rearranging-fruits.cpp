class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n1 = basket1.size();
        int n2 = basket2.size();

        map<int,int>count;
        map<int,int>freq;

        for(auto fruit : basket1){
           count[fruit]++;
           freq[fruit]++;

        }
        for(auto fruit : basket2){
            count[fruit]--;
            freq[fruit]++;
        }
       vector<int>extras;
       for(auto & [num,c]:count){
        if(c%2 != 0)return -1;
        for(int i = 0 ;i < abs(c)/2;i++)
            extras.push_back(num);
       }
        sort(extras.begin(),extras.end());
        int mini = freq.begin()->first;
        long long ans = 0;
        int n = extras.size();
        for(int i = 0 ; i < n/2 ; i++){
            ans += min(2LL*mini,1LL*extras[i]);
        }
    return ans;
    }
};