class Solution {
public:
    int maximum69Number (int num) {
       string n = to_string(num);
       for(auto &s:n){
        if(s=='6'){
            s = '9';
            break;
        }
       }
       return stoi(n);
    }
};


//Brute force 
// class Solution {
// public:
//     int maximum69Number (int num) {
//         vector<int>num69;
//         while(num){
//             int last = num%10;
//             num /= 10;
//             num69.push_back(last);
//         }
//         for(int  i = num69.size()-1; i >=0 ;i--){
//             if(num69[i]==6){
//                 num69[i]=9;
//                 break;
//             }
//         }
//         long long ans = 0;
//         for( int i = num69.size()-1 ; i >=0 ;i--){
//             ans = ans*10+num69[i];
//         }
//         return ans;
//     }
// };