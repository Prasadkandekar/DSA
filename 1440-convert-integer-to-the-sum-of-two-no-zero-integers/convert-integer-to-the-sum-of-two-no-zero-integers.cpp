class Solution {
public:
    bool NoZero(int n){
        
        while(n){
            int last = n%10;
            if(last == 0)return false;
            n = n/10;
            
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1 ; i < n ;i++){
            int a = i;
            int b = n-i;
       
            if(NoZero(a) && NoZero(b)){
                return {a,b};
            }
        }
        return {-1,-1};
    }
};


//Idea based , 70% testcases passed;
//     vector<int> getNoZeroIntegers(int n) {
//         bool isEven = false;
//         if(n%2==0)isEven = true;
//         if(isEven)return {n/2,n/2};
//         return {n/2,n/2+1};
//     }
// };