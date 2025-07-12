class Solution {
public:
    void fill(vector<vector<int>>&image,int y, int x, int color , int newColor){
        if(y <0 || y >= image.size() || x < 0 || x >= image[y].size() || image[y][x] != color)return;

        image[y][x] = newColor;
        fill(image,y,x+1,color , newColor);
        fill(image,y,x-1,color , newColor);
        fill(image,y-1,x,color , newColor);
        fill(image,y+1,x,color , newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor)return image;
   
    //recursive flood fill
    fill(image,sr,sc,image[sr][sc],newColor);
    return image;
    }
};