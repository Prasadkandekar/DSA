class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int num:nums){
            sum +=num;
        }
        return sum%k;
    }
};