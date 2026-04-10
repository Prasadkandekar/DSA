class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();

        int cnt = 0;

        for(int i = 0 ; i < n ;i++){
            int num = nums[i];
            int digi_cnt = 0;
            while(num){
                digi_cnt++;
                num /= 10;
            }
            if(digi_cnt%2==0)cnt++;
        }
    return cnt;
    }
};