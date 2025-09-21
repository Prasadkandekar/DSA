class Solution {
public:
    void backtrack(int index , string current , string digits , vector<string>&ans, vector<string> mappings){
        if(index == digits.size()){
            ans.push_back(current);
            return;
        }

        string letters = mappings[digits[index] - '0'];
        cout<<"Letters" << letters<<endl;

        for(char ch : letters){
            backtrack(index+1,current+ch,digits ,ans,mappings);
        }


    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return {};

        vector<string>mappings = {
            "","",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        vector<string>ans;
        backtrack(0,"",digits,ans,mappings);
        return ans;
    }
};