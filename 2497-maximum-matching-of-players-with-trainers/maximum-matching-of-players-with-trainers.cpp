class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n ;
       
        sort(trainers.begin(),trainers.end());
        sort(players.begin(),players.end());
      
        int i = 0;
        int j = 0;
        while(i < players.size() && j < trainers.size()){
            if(players[i]  <= trainers[j]){
             
                i++;
                j++;
            }else j++;
        }

        return i;
    }
};

