class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0 ;
        int r = 0;
        int jumps = 0 ;
        while(r < n-1){
            int f = 0;
            for(int j= l ; j <= r ;j++){
                f = max(j+nums[j],f);
            }
            l = r+1;
            r = f;
            jumps++;
        }
        return jumps;
    }
};