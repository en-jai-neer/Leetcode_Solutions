//Recursive
class Solution {
private:
    int cntlcs(int i, int j)
    {
        if(i == a.size() || j == b.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(a[i] == b[j])
        {
            dp[i][j] = cntlcs(i+1, j+1) + 1;
        }
        else
        {
            dp[i][j] = max(cntlcs(i+1, j), cntlcs(i, j+1));
        }
        return dp[i][j];
    }
    
public:
    string a, b;
    vector<vector<int>> dp;
    int longestCommonSubsequence(string _a, string _b) {
        a = _a;
        b = _b;
        dp.clear();
        dp.resize(a.size(), vector<int> (b.size(), -1));
        int ans = cntlcs(0, 0);
        return ans;
    }
};

//Iterative
public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(a[i] == b[j])
                    dp[i+1][j+1] = dp[i][j] + 1;
                else
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[n][m];
    }
};
