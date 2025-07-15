class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            stack<int>st;
            unordered_map<int,int>nextGreaterElementMap;

            //lets first insert in to stack and precompute nge in map

            for(auto num : nums2){
            while(!st.empty() && st.top() < num){
                nextGreaterElementMap[st.top()] = num;
                st.pop();
            }
            st.push(num);
            }

            while(!st.empty()){
                nextGreaterElementMap[st.top()] = -1;
                st.pop();
            }

            // now lets make the result happen
            vector<int>ans;
            for(auto num : nums1){
                ans.push_back(nextGreaterElementMap[num]);
            }
            return ans;
    }
};