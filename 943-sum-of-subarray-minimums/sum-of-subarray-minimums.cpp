class Solution {
    private:
    vector<int> findNSE(vector<int>&arr){
        int n = arr.size();
        vector<int>nse(n,n);
        stack<int>st;
        for(int i =n-1 ; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])st.pop();

            nse[i] = (st.empty())?n: st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPSEE(vector<int>&arr){
        int n = arr.size();
        vector<int>psee(n,-1);
        stack<int>st;

        for(int i = 0 ; i < n ;i++){
            while(!st.empty() && arr[st.top()] > arr[i])st.pop();

            psee[i] = (st.empty())?-1:st.top();
            st.push(i);
        }
        return psee;
    }
public:
    long long mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>nse = findNSE(arr);
        vector<int>psee = findPSEE(arr);
        long long minSum = 0;

        for(int i = 0 ;i < n ;i++){
            long long left = i-psee[i];
            long long right = nse[i]-i;

            minSum = (minSum + (right*left*arr[i])%mod)%mod;

        }
        return minSum;
    }
};

//Bruteforce --> Time Limit Exceeded
// class Solution {
// public:
//     long long modNum = 1e9+7;
//     int sumSubarrayMins(vector<int>& arr) {
//         if(arr.size()==1)return arr[0];
//         long long minSum = 0;
//         int n = arr.size();
//         for(int i = 0 ;i < n ; i++ ){
//             for(int j = i ; j < n  ; j++){
//                 minSum += *min_element(arr.begin()+i,arr.begin()+j+1);
//             }
//         }
//         return minSum%modNum;
//     }
// };