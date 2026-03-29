class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
      
        string str = to_string(k);
        cout << str <<endl;
        int m= str.size();
        cout << "m,n : " << m << " "<< n<<endl;
        int l = max(n,m)+1;
        vector<int> res(l,0);

        int carry =0;
        int i = n-1;
        int j = m-1;
        int r = l-1;
        while(i >= 0 || j >= 0 || carry){
            int ival = (i >= 0) ? num[i] : 0;
            i--;
            int jval = (j >= 0)?  str[j]-'0' : 0;
            j--;

            int sum = ival + jval + carry;
            res[r] = sum%10;
            carry = sum/10;
            r--;
        }

        vector<int>ans;
        bool isLeadZero = true;
        for(int i = 0 ;i < l ; i++){
            if(res[i]==0 && isLeadZero){continue;}
            else{
                isLeadZero = false;
                ans.push_back(res[i]);
            }

            
        }

    return ans;
    }
};