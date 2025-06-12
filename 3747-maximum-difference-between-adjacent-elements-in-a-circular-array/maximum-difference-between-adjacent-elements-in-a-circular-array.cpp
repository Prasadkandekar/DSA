class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1)return 0;
        int n = nums.size();
        int maxdiff = 0;
        int adjdiff = abs(nums[0]-nums[n-1]);
        for(int i = 0 ;i < n-1;i++){
                maxdiff = max(maxdiff,abs(nums[i]-nums[i+1]));
        }
        return max(maxdiff,adjdiff);

    }
};