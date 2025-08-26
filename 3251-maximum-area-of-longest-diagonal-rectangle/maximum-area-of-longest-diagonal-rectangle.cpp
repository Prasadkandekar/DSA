class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        // vector<int,int>params //stores length and area
       double maxlen = 0;
       double maxarea = 0;

        for(int i = 0 ;i < n ;i++ ){
            double length = sqrt(dimensions[i][0]*dimensions[i][0] +
                                     dimensions[i][1]*dimensions[i][1]);
            double area = (double)dimensions[i][0]*dimensions[i][1];
            if(length > maxlen || (length == maxlen && area > maxarea)){
                maxlen = length;
                maxarea = area;
            }
        }
        return maxarea;
    }
};