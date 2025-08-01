class Solution {
public:
    vector<int> generateRow(int row){
        vector<int>ansRow;
        long long ans = 1;
        ansRow.push_back(1);

        for(int col=1 ; col < row ; col++){
            
            ans = ans*(row-col);
            ans = ans/col;
            ansRow.push_back(ans);

        }

        return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        for(int row = 1 ; row<= numRows;row++){
            vector<int> temp;
            temp = generateRow(row);
            ans.push_back(temp);
        }

        return ans;
    }
};