class Solution {

public:
    int addDigits(int num) {
        if(num==0)return 0;
        return 1+(num-1)%9;
    }
};

//Recursive solution:

// class Solution {

// public:
//     int addDigits(int num) {
//         int ans = num;
//         int sum=0;
//         while(ans){
//             int last = ans%10;
//             sum +=last;
//             ans = ans/10;
//         }
//         if(sum >9){
//        sum =  addDigits(sum);
//         }
//          return sum;
//     }
// };