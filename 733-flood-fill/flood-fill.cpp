class Solution {
private:
    void dfs(vector<vector<int>>& image, int r , int c , int color ,int startColor){
        int n = image.size();
        int m = image[0].size();

        if(r < 0 || r >= n || c < 0 || c >= m)return;
        if(image[r][c] !=startColor)return;

        image[r][c]  = color;

     
        dfs(image,r+1,c,color,startColor);
        dfs(image,r,c+1,color,startColor);
        dfs(image,r-1,c,color,startColor);
        dfs(image,r,c-1,color,startColor);
        
        
        
       

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         int n = image.size();
         int m = image[0].size();

        int startColor = image[sr][sc];
        if(startColor == color)return image;
        dfs(image,sr,sc,color,startColor);
         return image;
    }
};