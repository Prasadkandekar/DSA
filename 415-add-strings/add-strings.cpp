class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1 == "0" && num2== "0")return "0";
        int m = num1.size();
        int n = num2.size();
        int k = max(m,n) + 1;
        vector<int>res(k,0);
        int i = n-1;
        int j = m-1;
        int carry = 0;
        int r = k-1;
        while(i >= 0 || j >= 0 || carry){
            int ival = (i >= 0) ? num2[i]-'0' : 0;
            int jval = (j >= 0 ) ? num1[j]-'0' : 0;
            i--;
            j--;

            
          

            int sum = ival + jval + carry;

            res[r] = sum%10;
            carry = sum/10;
            r--; 
        }


        for(int i = 0 ;i < k ; i++){
            cout << res[i] << " ";
        }
    
        string ans = "";
        bool isLeadZero = true;
        for(int i = 0 ;i < k ;i++){
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