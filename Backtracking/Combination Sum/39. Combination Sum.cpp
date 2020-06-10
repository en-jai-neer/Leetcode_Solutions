class Solution {
private:
    void solve(vector<int>& candidates, int target, int ind, vector<int>& cur)
    {
        if(ind < 0)
            return;
        if(candidates[ind] <= target)
        {
            cur.push_back(candidates[ind]);
            if(target == candidates[ind])
                ans.push_back(cur);
            else
                solve(candidates, target-candidates[ind], ind, cur);
            cur.pop_back();
        }
        solve(candidates, target, ind-1, cur);
    }
    
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        solve(candidates, target, candidates.size()-1, cur);
        return ans;
    }
};

//Template
class Solution {
private:
    void solve(vector<int>& candidates, int target, int start, vector<int>& cur)
    {
        if(target < 0)
            return;
        if(target == 0)
            ans.push_back(cur);
        for(int i = start; i < candidates.size(); i++)
        {
            cur.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i, cur);
            cur.pop_back();
        }
    }
    
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        solve(candidates, target, 0, cur);
        return ans;
    }
};
