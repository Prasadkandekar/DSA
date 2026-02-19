class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if(mat.empty())return mat;

        int m = mat.size();
        int n = mat[0].size();

        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>> dist(m,vector<int>(n,0));
        vector<vector<int>> visited(m,vector<int>(n,0));

        for(int i = 0 ;i < m ;i++){
            for(int j = 0 ;j < n ;j++){
                if(mat[i][j]==0){
                    visited[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }
            int drow[4] = {-1,0,1,0};
            int dcol[4] = {0,-1,0,1};
            int min_dist = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int curr_dist = q.front().second;
            dist[row][col] = curr_dist;
            q.pop();

            for(int i = 0 ;i <  4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >=0 && nrow < m && ncol >=0 && ncol < n && !visited[nrow][ncol]){
                    visited[nrow][ncol] = 1;
                    q.push({{nrow,ncol},curr_dist+1});
                   
                }
            }
        }
    return dist;
    }
};