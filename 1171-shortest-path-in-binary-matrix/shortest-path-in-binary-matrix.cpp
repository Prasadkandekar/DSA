class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;
        q.push({{0,0},0});
        visited[0][0] =1;

        int drow[] = {0,0,1,1,1,-1,-1,-1};
        int dcol[] = {1,-1,0,1,-1,0,1,-1};
       
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int currDist = q.front().second;
            q.pop();
            if(n-1==row && m-1==col && visited[row][col]==1)return currDist + 1;
            
            
            for(int i = 0 ;i < 8 ;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

               if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol]==0){
                    visited[nrow][ncol] = 1;
                    q.push({{nrow,ncol},currDist+1});
               }
            }
        }
      
    return -1;;
    }
};