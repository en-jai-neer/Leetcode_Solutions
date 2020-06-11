//2D Recursive
class Solution {
private:
    int solve(vector<int>& coins, int amount, int i)
    {
        if(amount == 0)
            return 1;
        if(i < 0 || amount < 0)
            return 0;
        if(dp[amount][i] != -1)
            return dp[amount][i];
        return dp[amount][i] = solve(coins, amount, i-1) + solve(coins, amount - coins[i], i);
    }
    
public:
    vector<vector<int>> dp;
    int change(int amount, vector<int>& coins) {
        dp.clear();
        dp.resize(amount+1, vector<int> (coins.size(), -1));
        return solve(coins, amount, coins.size()-1);
    }
};

//2D Iterative
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(n == 0 && amount == 0)
            return 1;
        if(n == 0)
            return 0;
        vector<vector<int>> dp(amount+1, vector<int> (n));
        for(int i = 0; i < n; i++)
            dp[0][i] = 1;
        for(int i = 1; i <= amount; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(j != 0)
                    dp[i][j] = dp[i][j-1];
                if(i - coins[j] >= 0)
                    dp[i][j] += dp[i-coins[j]][j];
            }
        }
        return dp[amount][n-1];
    }
};

//2D Iterative
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int> (n+1));
        for(int i = 0; i < n+1; i++)
            dp[0][i] = 1;
        for(int i = 1; i <= amount; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                dp[i][j] = dp[i][j-1];
                if(i - coins[j-1] >= 0)
                    dp[i][j] += dp[i-coins[j-1]][j];
            }
        }
        return dp[amount][n];
    }
};

//1D Iterative
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1);
        dp[0] = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j <= amount; j++)
            {
                if(j-coins[i] >= 0)
                    dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};
