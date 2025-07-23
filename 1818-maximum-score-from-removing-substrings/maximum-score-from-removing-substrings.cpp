class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        if(x<y){
            swap(x,y);
            reverse(s.begin(),s.end());
        }

        stack<char>st;
        string remaining;


        for(char c : s){
            if(!st.empty() && st.top()=='a' && c == 'b'){
                st.pop();
                ans += x;
            }else{
                st.push(c);
            }
        }

        while(!st.empty()){
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(),remaining.end());

        for(char c : remaining){
            if(!st.empty() && st.top() =='b' && c == 'a'){
                st.pop();
                ans += y;
            }else{
                st.push(c);
            }
        }
        return ans;
    }
};