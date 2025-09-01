class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int neg = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0 ;i < m ;i++){
           int l = 0; int r = n-1;

            while ( l <= r){
                int mid = (l+r)/2;
                if(grid[i][mid] < 0){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
           neg  += (n-l);
        }
        return neg;
    }
};