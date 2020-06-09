// 2D Top down (Memoization) - [Although the Time Complexity of all the solutions is same but top down is faster because it does not 
// calculate all n*sum states, it only calculates the states that are necessary.]
class Solution {
private:
    int topDown(vector<int>& nums, int n, int sum)
    {
        if(sum == 0)
            return true;
        if(n == 0)
            return false;
        if(dp[n][sum] != -1)
            return dp[n][sum];
        if(sum - nums[n-1] >= 0)
            dp[n][sum] = topDown(nums, n-1, sum - nums[n-1]) || topDown(nums, n-1, sum);
        else
            dp[n][sum] = topDown(nums, n-1, sum);
        return dp[n][sum];
    }
    
public:
    vector<vector<int>> dp;
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i: nums)
            sum += i;
        if(sum % 2 == 1)
            return false;
        sum /= 2;
        dp.clear();
        dp.resize(n+1, vector<int> (sum+1, -1));
        return topDown(nums, n, sum);
    }
};

//*********************************************************************************************************************************//
//2D Bottom Up
public:
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i: nums)
            sum += i;
        if(sum % 2 == 1)
            return false;
        sum /= 2;
        vector<vector<bool>> dp(n+1, vector<bool> (sum+1, false));
        for(int i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                if(j - nums[i-1] >= 0)
                {
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};

//*********************************************************************************************************************************//
//1D Bottom Up
// Every loop of nums refreshes dp array. We might get dp[i] from dp[i-num] whose index is smaller than i. If we increase the index of // sum from 0 to sum, we will get dp[i] from dp[i-num] , while dp[i-num] has been updated in this loop. This dp[i-num] is not the number // we got from the previous loop.

// So why would we do this? This is because the numbers in nums can only be used once. If we can choose each number several times, we 
// have to increase i from 0 to sum (Unbounded Knapsack - Coin Change problems)

public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i: nums)
            sum += i;
        if(sum % 2 == 1)
            return false;
        sum /= 2;
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for(int i = 0; i < n; i++)
        {
            for(int j = sum; j >= 0; j--)
            {
                if(j - nums[i] >= 0)
                    dp[j] = dp[j-nums[i]] || dp[j];
            }
        }
        return dp[sum];
    }
};
