class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int i = 0 , j = 0;
        int jumps = 0;

        while(j < n-1){
            int farthest = 0;
            for(int k = i ; k <= j ; k++){
                farthest = max(farthest,k + nums[k]);
            }
            i = j+1;
            j = farthest;
            jumps++;
        }
    return jumps;
    }
};