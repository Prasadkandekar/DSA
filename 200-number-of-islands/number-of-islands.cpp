class Solution {
private:
    void bfs( int row, int col , vector<vector<char>>& grid, vector<vector<int>>& visited){

        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        visited[row][col] =1;

        // int dx[] = {1,1,1,0,0,-1,-1,-1};
        // int dy[] = {1,0,-1,1,-1,1,0,-1};

        int dx[] = {1,0,-1,0};
        int dy[] = {0,-1,0,1};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0 ;i < 4 ;i++){
                int nrow = x + dx[i];
                int ncol = y + dy[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol]=='1' && !visited[nrow][ncol]){
                    visited[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }

        }
    }
    void dfs( int row, int col , vector<vector<char>>& grid, vector<vector<int>>& visited){
        
        int n = grid.size();
        int m = grid[0].size();

        
            visited[row][col]=1;
        

        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};

        for(int i = 0 ;i < 4 ;i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && grid[nrow][ncol]=='1' && !visited[nrow][ncol]){
                dfs(nrow,ncol,grid,visited);
            }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        vector<vector<int>>visited(n,vector<int>(m,0));
        
        for(int i = 0 ;i < n ; i++){
            for(int j= 0 ; j<m ; j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    count++;
                    // bfs(i,j, grid, visited);
                     dfs(i,j, grid, visited);
                }
            }
        }


        return count;
    }
};