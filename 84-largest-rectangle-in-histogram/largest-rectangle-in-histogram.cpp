class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n  = heights.size();
        int maxArea = 0;
        stack<int>st;
        int eleIdx;
        int nse;
        int pse;

        for(int i = 0; i < n ;i++){
            while(!st.empty() && heights[st.top()]> heights[i]){
                nse = i;
                eleIdx = st.top();st.pop();
                pse = (st.empty())?-1:st.top();
                maxArea = max(maxArea,heights[eleIdx]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            nse = n;
            eleIdx = st.top();st.pop();
            pse = (st.empty())?-1:st.top();
            maxArea = max(maxArea,heights[eleIdx]*(nse-pse-1));
        }
        return maxArea;
    }
};