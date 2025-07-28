class Solution {
public:
    int subsets(int idx , vector<int>& nums , int currOR , int maxOR){
        if(idx == nums.size()){
            if(currOR==maxOR)return 1;

            return 0;
        }

        int taken = subsets(idx+1,nums,currOR |nums[idx] , maxOR);

        int not_taken = subsets(idx+1,nums,currOR,maxOR);

        return taken + not_taken;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOR = 0;

        for(int i=0; i<n; i++){
            maxOR = maxOR | nums[i];
        }
       
       int currOR = 0;

       return subsets(0,nums,currOR,maxOR);
    }
};