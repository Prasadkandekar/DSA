class NumArray {
public: 
    vector<int>prefixSumArr;
    NumArray(vector<int>& nums) {
        for(int i = 1 ; i< nums.size();i++){
            nums[i] += nums[i-1];
        }
        this->prefixSumArr = nums;
    }
    
    int sumRange(int left, int right) {
      if(left==0)return prefixSumArr[right];

      return prefixSumArr[right]-prefixSumArr[left-1];
      
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */