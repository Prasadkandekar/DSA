class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        if(grid.empty())return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int count = 0;
        queue<pair<int,int>>q;

        for(int i= 0 ;i< m;i++){
            for(int j = 0 ; j < n; j++){
                if((i==0 || j==0 || i == m-1 || j==n-1) && grid[i][j]==1){
                    visited[i][j] = 1;
                    q.push({i,j});
                }
            }
        }

        int drow[] = {1,0,-1,0};
        int dcol[] = {0,-1,0,1};

        while(!q.empty()){
            int row =  q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i= 0; i < 4 ;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >=0 && nrow < m && ncol >=0 && ncol < n && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                    visited[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }

            }
        }
         for(int i=0 ; i < m ;i++){
                for(int j=0 ; j < n ; j++){
                    if(!visited[i][j] && grid[i][j]==1){
                        count++;
                    }
                }
            }

    return count;
    }
};