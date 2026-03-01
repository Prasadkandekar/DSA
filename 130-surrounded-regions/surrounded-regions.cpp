class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int i = 0 ; i< n ;i++){
            for(int j = 0 ;j<m ; j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(board[i][j]=='O' && !visited[i][j] ){
                        q.push({i,j});
                        visited[i][j] =1;
                    }
                }
            }
        }

        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0 ; i < 4 ; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >=0 && nrow < n && ncol >=0  && ncol < m && !visited[nrow][ncol] && board[nrow][ncol]=='O'){
                    q.push({nrow,ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }

        for(int i = 0 ;  i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }




    }
};