class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m,vector<int>(n,0));

        queue<pair<int,int>> q;

        for(int i = 0 ;i < m ; i++){
            for(int j = 0 ;j < n ;j++){
                if(board[i][j]=='O' && !visited[i][j] && (i==0 || j==0 || i == m-1 || j == n-1)){
                    visited[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
       

       int drow[] = { 1,0,-1,0};
       int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
             q.pop();

            for(int i = 0 ;i < 4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
               

                
                    if( nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && !visited[nrow][ncol] && board[nrow][ncol]=='O' ){
                        if(!visited[nrow][ncol]){
                        visited[nrow][ncol] = 1;// all boundries will be visited
                        q.push({nrow,ncol});
                    }
                }
            }

        }

        for(int i = 0 ; i < m ;i++){
            for(int j = 0; j < n ;j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};