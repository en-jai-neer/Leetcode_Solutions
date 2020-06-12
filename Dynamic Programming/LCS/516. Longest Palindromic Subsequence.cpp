//Recursive by finding the lcs between s and reverse of s
class Solution {
private:
    int solve(int i, int j)
    {
        if(i == n || j == n)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans;
        if(s[i] == t[j])
            ans = solve(i+1, j+1) + 1;
        else
            ans = max(solve(i, j+1), solve(i+1, j));
        return dp[i][j] = ans;
    }
public:
    string s, t;
    int n;
    vector<vector<int>> dp;
    int longestPalindromeSubseq(string _s) {
        s = _s;
        t = s;
        reverse(t.begin(), t.end());
        n = s.size();
        dp.clear();
        dp.resize(n, vector<int> (n, -1));
        return solve(0, 0);
    }
};

//Recursive
class Solution {
private:
    int solve(int i, int j)
    {
        if(i == n || j < 0 || i > j)
            return 0;
        if(i == j)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans;
        if(s[i] == s[j])
            ans = solve(i+1, j-1) + 2;
        else
            ans = max(solve(i, j-1), solve(i+1, j));
        return dp[i][j] = ans;
    }
public:
    string s;
    int n;
    vector<vector<int>> dp;
    int longestPalindromeSubseq(string _s) {
        s = _s;
        n = s.size();
        dp.clear();
        dp.resize(n, vector<int> (n, -1));
        return solve(0, n-1);
    }
};

//Iterative
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n));
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = i; j < n; j++)
            {
                if(i == j)
                    dp[i][j] = 1;
                else if(i+1 < n && j-1 >= 0 && s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else 
                {
                    if(i+1 < n)
                        dp[i][j] = max(dp[i][j], dp[i+1][j]);
                    if(j-1 >= 0)
                        dp[i][j] = max(dp[i][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};

//Iterative by iterating over all possible lengths
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n));
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 0; j+i-1 < n; j++)
            {
                int k = j+i-1;
                if(s[k] == s[j] && i==2)  
                    dp[j][k] = 2;
                if(s[k] == s[j])
                {
                    dp[j][k] = dp[j+1][k-1] + 2;
                }
                else
                {
                    dp[j][k] = max(dp[j][k-1], dp[j+1][k]);
                }
            }
        }
        return dp[0][n-1];
    }
};
