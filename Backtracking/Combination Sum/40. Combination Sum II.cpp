class Solution {
private:
    void solve(vector<int>& candidates, int target, int start, vector<int>& cur)
    {
        if(target == 0)
            ans.push_back(cur);
        if(target <= 0)
            return;
        for(int i = start; i < candidates.size(); i++)
        {
            if(i > start && candidates[i] == candidates[i-1])
                continue;
            cur.push_back(candidates[i]);
            solve(candidates, target-candidates[i], i+1, cur);
            cur.pop_back();
        }
    }
    
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, cur);
        return ans;
    }
};
