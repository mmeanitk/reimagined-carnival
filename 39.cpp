class Solution {
    
private:
    void solve(vector<int> candidates, int target, vector<vector<int>>& ans, int index, int sum, vector<int> output) {
        if(sum==target) {
            ans.push_back(output);
            return;
        }
        else if(sum>target)
            return;
        
        for(int i=index;i<candidates.size();i++) {
            output.push_back(candidates[i]);
            sum+=candidates[i];
            solve(candidates, target, ans, i, sum, output);
            output.pop_back();
            sum-=candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int index = 0, sum = 0;
        vector<int> output;
        solve(candidates, target, ans, index, sum, output);
        
        return ans;
    }
};
