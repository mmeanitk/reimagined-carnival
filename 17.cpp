class Solution {

private:
    void solve(string digits, vector<string>& ans, string output, int index, vector<string> mapping) {
        if(index>=digits.size())
        {
            ans.push_back(output);
            return;
        }
        int num = digits[index]-'0';
        string val = mapping[num];
        for(int i=0;i<val.size();i++) {
            output.push_back(val[i]);
            solve(digits, ans, output, index+1, mapping);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int index = 0;
        if(digits.size()==0) return ans;
        string output;
        vector<string> mapping {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, ans, output, index, mapping);
        return ans;
        
    }
};
