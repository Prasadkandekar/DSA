class Solution {
private:
int largestHistogram(vector<int> arr){
    int n = arr.size();
    int maxArea = 0;
    stack<int>st;
    int eleIdx;
    int nse;
    int pse;

    for(int i = 0 ;i < n ;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            nse = i;
            eleIdx = st.top();st.pop();
            pse =  (st.empty())?-1:st.top();
            maxArea = max(maxArea,(nse-pse-1)*arr[eleIdx]);
        }
        st.push(i);
    }
    while(!st.empty()){
        nse = n;
        eleIdx = st.top();st.pop();
        pse = (st.empty())?-1:st.top();
        maxArea = max(maxArea,arr[eleIdx]*(nse-pse-1));
    }
    return maxArea;
}
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;

        //prefix sum matrix for ease:
        vector<vector<int>>pSum(n,vector<int>(m,0));

        for(int j = 0 ;j < m ; j++){
            int sum = 0;
            for(int i = 0 ; i < n ;i++){
                if(matrix[i][j]== '1'){
                sum  += 1;
                }else{
                    sum = 0;
                }
                pSum[i][j] = sum;
            }
        }

        for(int i = 0 ;i < n ;i++){
            maxArea = max(maxArea , largestHistogram(pSum[i]));
        }
        return maxArea;
    }
};