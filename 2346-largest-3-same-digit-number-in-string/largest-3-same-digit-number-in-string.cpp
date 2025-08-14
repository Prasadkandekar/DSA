class Solution {
public:
    string largestGoodInteger(string num) {
      
    vector<string>nums = {"999","888","777","666","555","444","333","222","111","000"};
    for(int i = 0 ;i < nums.size(); i++){
        if(num.find(nums[i]) != std::string::npos){
            return nums[i];
        }
    }

    return "";
    }
};