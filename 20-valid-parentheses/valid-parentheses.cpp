class Solution {
public:
    bool isMatchingPair(char open , char close){
        int xorVal  = open^close;
        return xorVal==1 || xorVal==2 || xorVal==6;
    }
    bool isValid(string s) {
        
        stack<int>st;

        for(auto ch : s){
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }else{
                if(st.empty())return false;
                char top = st.top();st.pop();
                
                if(!isMatchingPair(top,ch))return false;
            }
        }
    return st.empty();
    }
};