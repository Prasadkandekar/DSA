class Solution {
public:
    int averageValue(vector<int>& nums) {
        int cnt= 0;
        int evenSum = 0;
        for(int i = 0 ;i < nums.size() ;i++){
            if(nums[i]%2==0 && nums[i]%3==0){
                cnt++;
                evenSum += nums[i];
            }
        }
        return (cnt)?(evenSum/cnt):0;
    }
};