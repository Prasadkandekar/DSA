class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& image,int color,vector<vector<int>>& visited, int startColor){
        int n = image.size();
        int m = image[0].size();
        
         visited[row][col] = 1;
         image[row][col] = color;

         int drow[] = {1,0,-1,0};
         int dcol[] = {0,1,0,-1};

         for(int i = 0  ; i < 4 ;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            

            if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && image[nrow][ncol]==startColor){
                dfs(nrow,ncol,image,color,visited,image[nrow][ncol]);
            }
         }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        int startColor = image[sr][sc];
        dfs(sr,sc,image,color,visited,startColor);
        return image;
    }
};