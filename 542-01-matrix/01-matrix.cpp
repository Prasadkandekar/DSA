class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<tuple<int,int,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(mat[i][j]==0){
                    q.emplace(i,j,0);
                    visited[i][j] = 1;
                }
            }
        }

        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            auto [row,col,curr_dist] = q.front();
            dist[row][col] = curr_dist;
            q.pop();

            for(int i = 0; i < 4 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && !visited[nrow][ncol]){
                    visited[nrow][ncol] = 1;
                    q.emplace(nrow,ncol,curr_dist+1);
                }
            }

        }

        return dist;
    }
};