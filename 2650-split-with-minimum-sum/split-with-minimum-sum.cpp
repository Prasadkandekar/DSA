class Solution {
public:
    int splitNum(int num) {
        vector<int>arr;
        int temp = num;
        while(temp){
            int last = temp%10;
            temp = temp/10;
            arr.push_back(last);
        }
        sort(arr.begin(),arr.end());
        int digi1 = 0;
        int digi2 = 0;
        
        for(int i = 0 ; i<arr.size() ;i++){
            if(i%2==0){
                digi1 = digi1*10 + arr[i];
            }else{
                digi2 = digi2*10+arr[i];
            }
        }

    return digi1+digi2;

    }
};