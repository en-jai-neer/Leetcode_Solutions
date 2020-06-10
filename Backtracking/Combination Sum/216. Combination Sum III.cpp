class Solution {
private:
    void solve(int k, int n, int start, vector<int>& cur)
    {
        if(n == 0 && k == 0)
            ans.push_back(cur);
        if(n <= 0 || k <= 0)
            return;
        for(int i = start; i <= 9; i++)
        {
            cur.push_back(i);
            solve(k-1, n-i, i+1, cur);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur;
        solve(k, n, 1, cur);
        return ans;
    }
};
