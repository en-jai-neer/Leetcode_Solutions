//Iterative 1D
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        
        for(int i = 2; i < n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                dp[i] = max(dp[i], j*dp[i-j]);
            }
        }
        
        //dp[n] = partition from 1 to n-1. Dont include the partition 0, n.
        for(int j = 1; j < n; j++)
        {
            dp[n] = max(dp[n], j*dp[n-j]);
        }
        return dp[n];
    }
};

//************************************************************************************************************************************//
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
