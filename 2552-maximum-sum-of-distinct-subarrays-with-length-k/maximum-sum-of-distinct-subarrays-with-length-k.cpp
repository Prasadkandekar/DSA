class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        long long ans = 0;
        long long sum = 0;
        unordered_map<int,int>freq;

        while(right < n){

            //1 include the element in map and increase sum
            freq[nums[right]]++;
            sum += nums[right];

            // shrink if window size is greater than k

            if( right - left +1 > k){
                // decrese freq and sum
                freq[nums[left]]--;//may be left
                // sum[nums[left]]--; its wrong syntax
                sum -= nums[left];
                if(freq[nums[left]]==0)freq.erase(nums[left]);
                left++;
            }

            if(right - left +1 == k){
                if(freq.size()==k){
                    ans = max(ans,sum);
                }
            }
            right++;
        }
    return ans;
    }
};