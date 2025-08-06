class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = baskets.size();
        int unplaced = 0;
        vector<bool>seen(m,false);

        for(int i = 0 ;i < n ;i++){
            bool placed = false;
            for(int  j = 0 ;j < m ; j++){
                if(!seen[j] && baskets[j] >= fruits[i]){
                    seen[j] = true;
                    placed = true;
                    break;
                }
            }
            if(!placed)unplaced++;
        }
        return unplaced;
    }
};