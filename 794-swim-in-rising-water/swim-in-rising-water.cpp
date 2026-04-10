class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
         int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        
        pq.push({grid[0][0],{0,0}});
        dist[0][0] = 0;

        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == m-1 && dist[row][col] != 1e9 )return diff;
            for(int i = 0 ;i < 4 ;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0  && nrow < n && ncol >= 0 && ncol < m ){

                    int newTime = max(grid[nrow][ncol],diff);

                    if(newTime < dist[nrow][ncol]){
                        dist[nrow][ncol] = newTime;
                        pq.push({newTime,{nrow,ncol}});
                    }
                }
            }

        }
       return dist[n-1][m-1];
    }
};