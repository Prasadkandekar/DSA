class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        if(isWater.empty())return isWater;
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>>visited(m,vector<int>(n,0));
        vector<vector<int>>height(m,vector<int>(n,0));

        queue<pair<pair<int,int>,int>>q;

        for(int i = 0 ;i< m ;i++){
            for(int j = 0 ;j < n ;j++){
                if(isWater[i][j]==1){
                    visited[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }

        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            height[row][col] = dist;

            for(int i = 0 ;i < 4 ;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol]){
                    visited[nrow][ncol] = 1;
                    q.push({{nrow,ncol},dist+1});
                }
            }
        }
    return height;
    }
};