class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        //multi source bfs
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]==2 && !visited[i][j]){
                    q.push({{i,j},0});
                }
            }
        }

        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int currTime = q.front().second;
            q.pop();

            time = max(time,currTime);

            for(int i = 0 ;i < 4 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n  && ncol >= 0 && ncol < m && grid[nrow][ncol]==1 && !visited[nrow][ncol]){
                     visited[nrow][ncol] = 1;
                     q.push({{nrow,ncol},currTime+1});
                }
            }
            
        }


        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                   return -1;
                }
            }
        }

        return time ;
    }
};