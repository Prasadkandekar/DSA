class Solution {
public:
    int thirdMax(vector<int>& nums) {
       set<int>st;
       for(auto num : nums){
        st.insert(num);
       }

       if(st.size() < 3){
        return *st.rbegin();
       }else if(st.size() >=3){
         auto last = prev(st.end(),3);
         return *last;
       }

       return -1;

    }
};