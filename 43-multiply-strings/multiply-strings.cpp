class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();

        if(n1==1 && num1[0]=='0' || n2 == 1 && num2[0]=='0')return "0";

        vector<int>res(n1+n2 ,0);

        int i = n2-1;
        int pf = 0; // power factor

        while(i >= 0){

            int ival = num2[i]-'0';
            i--;

            int j = n1-1;
            int carry = 0;
            int k = res.size()-1-pf;

            while(j >= 0 || carry){
                int jval = (j >= 0)?num1[j]-'0' : 0;
                j--;
               
                

                 int prod = ival*jval + carry + res[k];
                 cout << prod << " ";
                 res[k] = prod%10;
                 carry = prod/10;
                 k--;
            }

            pf++;
        }

        //handling leading zeros and string ans creation
        string ans = "";

        bool isLeadZero = true;
        for(int i = 0; i < res.size() ;i++){
            if(res[i]==0 && isLeadZero){
                continue;
            }else{
                isLeadZero = false;
                ans += res[i]+'0';
            }
        }       
        return ans;
    }
};