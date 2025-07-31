class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        if(n==1)return 1;

        set<int>res;
        set<int>prev;

        for(int num : arr){
            set<int>curr;
            curr.insert(num);

            for(int x : prev){
                curr.insert(num|x);

            }

            for(int x : curr){
                res.insert(x);
            }
            prev = curr;
        }
       
    return res.size();
    }
};

//Brute force :
// class Solution {
// public:
//     int subarrayBitwiseORs(vector<int>& arr) {
//         int n = arr.size();
//         if(n==1)return 1;
//         set<int>st;

//         for(int i = 0 ;i < n;i++){
//             int bitOr = 0;
//             for(int j = i ; j < n;j++){
//                 bitOr |= arr[j];
//                st.insert(bitOr);
//             }
            
//         }
//     return st.size();
//     }
// };