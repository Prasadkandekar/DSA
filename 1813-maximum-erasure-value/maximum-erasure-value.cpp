class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int currentSum = 0;
        int maxSum = 0;
        unordered_set<int>seen;

        while(r < n){
            while(seen.count(nums[r])){
                seen.erase(nums[l]);
                currentSum -= nums[l];
                l++;
            }
            seen.insert(nums[r]);
            currentSum += nums[r];
            r++;
            maxSum = max(maxSum,currentSum);
        }
        return maxSum;
    }
};