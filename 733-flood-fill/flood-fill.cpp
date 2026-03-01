class Solution {
private:
    void dfs(int row,int col,vector<vector<int>>& image,int color, int startColor){
       
         int n = image.size();
         int m = image[0].size();
        
        if(row  < 0 || row >= n || col < 0 || col >= m || image[row][col] != startColor)return;
         image[row][col] = color;

         int drow[] = {1,0,-1,0};
         int dcol[] = {0,1,0,-1};

         for(int i = 0  ; i < 4 ;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m ){
                dfs(nrow,ncol,image,color,startColor);
            }
         }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startColor = image[sr][sc];
         if(startColor == color)return image;
        dfs(sr,sc,image,color,startColor);
        return image;
    }
};