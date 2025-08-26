class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        // vector<int,int>params //stores length and area
        vector<vector<double>>params;

        for(int i = 0 ;i < n ;i++ ){
            vector<double>temp;
            double length = sqrt(dimensions[i][0]*dimensions[i][0] +
                                     dimensions[i][1]*dimensions[i][1]);
            double area = (double)dimensions[i][0]*dimensions[i][1];
            temp.push_back(length);
            temp.push_back(area);
            params.push_back(temp);
        }

        sort(params.begin(),params.end());

        return (int) params[params.size()-1][1];
    }
};