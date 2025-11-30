class Solution {
public:
    bool checkIfPangram(string sentence) {
       int n = sentence.size();
       set<int>st;
       for(int i = 0 ;i< n ;i++){
            st.insert(sentence[i]);
       }
       if(st.size() == 26)return true;
       return false;
    }
};