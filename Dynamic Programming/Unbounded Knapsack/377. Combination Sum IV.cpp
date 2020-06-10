//Recursive
class Solution {
private:
    int solve(vector<int>& nums, int target)
    {
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        if(dp[target] != -1)
            return dp[target];
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ans += solve(nums, target-nums[i]);
        }
        return dp[target] = ans;
    }
public:
    vector<int> dp;
    int combinationSum4(vector<int>& nums, int target) {
        dp.clear();
        dp.resize(target+1, -1);
        return solve(nums, target);
    }
};

//Iterative
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1);
        dp[0] = 1;
        for(int i = 1; i <= target; i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(i - nums[j] >= 0)
                    dp[i] += dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};
