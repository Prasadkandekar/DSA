class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image.empty())return image;
        

        int m = image.size();
        int n = image[0].size();

        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};

        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>> visited(m,vector<int>(n,0));
        q.push({{sr,sc},image[sr][sc]});
        // image[sr][sc] = color;
        visited[sr][sc] = 1;

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int old_color = q.front().second;
            q.pop();
            image[row][col] = color;

            for(int i = 0 ; i < 4 ;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
               

                if(nrow >=0  && nrow < m && ncol >=0  && ncol < n && !visited[nrow][ncol] && image[nrow][ncol] == old_color){
                    q.push({{nrow,ncol},image[nrow][ncol]});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        return image;
    }
};