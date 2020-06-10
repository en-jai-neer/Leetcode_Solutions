//Recursive
class Solution {
private:
    int solve(vector<int>& coins, int amount)
    {
        if(amount == 0)
            return 0;
        if(dp[amount] != -1)
            return dp[amount];
        int ans = INT_MAX;
        for(int i = 0; i < coins.size(); i++)
        {
            int locAns = INT_MAX;
            if(amount - coins[i] >= 0)
                locAns = solve(coins, amount-coins[i]);
            if(locAns != INT_MAX)
                ans = min(ans, locAns+1);
        }
        return dp[amount] = ans;
    }
    
public:
    vector<int> dp;
    int coinChange(vector<int>& coins, int amount) {
        dp.clear();
        dp.resize(amount+1, -1);
        int ans = solve(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};

//Iterative
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            for(int j = 0; j < coins.size(); j++)
            {
                if(i-coins[j] >= 0)
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};
