class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        int preFixSum = 0;

        for(int num : nums){
            preFixSum += num;
            ans.push_back(preFixSum);
        }
        return ans;
    }
};