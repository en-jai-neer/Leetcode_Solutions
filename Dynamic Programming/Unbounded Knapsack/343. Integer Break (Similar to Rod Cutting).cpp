class Solution {
private:
    int solve(int n, int i)
    {
        if(n == 0)
            return 0;
        if(i == 0)
            return n;
        if(dp[n][i] != -1)
            return dp[n][i];
        int ans;
        if(i <= n)
        {
            ans = max(solve(n-i, n-i) * i, solve(n, i-1));
        }
        else
        {
            ans = solve(n, i-1);
        }
        return dp[n][i] = ans;
    }
    
public:
    vector<vector<int>> dp;
    int integerBreak(int n) {
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        dp.clear();
        dp.resize(n+1, vector<int> (n+1, -1));
        return solve(n, n);
    }
};
