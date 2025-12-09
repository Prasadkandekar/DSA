class Solution {
    
public:
    const long long mod = 1e9 +7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        map<long,long>rightCount;
        map<long,long>leftCount;

        for(int num : nums){
            rightCount[num]++;
        }

        for(int i = 0 ;i < n ;i++){
            
            long target = 2* nums[i];
            rightCount[nums[i]]--;
            long lcount = leftCount[target];
            long rcount = rightCount[target];

            ans = (ans + (lcount * rcount)%mod)%mod;

            leftCount[nums[i]]++;
        }
        return ans;
    }
};