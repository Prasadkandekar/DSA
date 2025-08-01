class Solution {
public:
    vector<int> getRow(int row) {
        long long ans = 1;
        row = row+1;
        vector<int>pascalRow;
        pascalRow.push_back(1);
        for(int col = 1;col < row; col++){
            ans = ans*(row-col);
            ans = ans/col;
            pascalRow.push_back(ans);
        }
        return pascalRow;
    }
};