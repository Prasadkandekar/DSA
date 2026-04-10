class Solution {
private:
    bool canReach(vector<vector<int>>&grid , int t){
        int n = grid.size();

        vector<vector<int>>visited(n,vector<int>(n,0));
        queue<pair<int,int>>q;
        q.push({0,0});
        visited[0][0] = 1;
        if(grid[0][0] > t)return false;

        int drow[] = {1,-1,0,0};
        int dcol[] = {0,0,1,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if(row==n-1 && col ==n-1)return true;

            for(int i = 0 ;i < 4 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !visited[nrow][ncol] && grid[nrow][ncol] <= t ){
                    visited[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        //Binary Search + BFS approach
        int n =grid.size();
        int left = grid[0][0];
        int right = n*n-1;
        int ans = right;

        while(left <= right){
            int mid = (right + left)/2;

            if(canReach(grid,mid)){
                ans = mid;
                right = mid-1;

            }else{
                left  = mid+1;
            }
        }

        return ans;
    }
};