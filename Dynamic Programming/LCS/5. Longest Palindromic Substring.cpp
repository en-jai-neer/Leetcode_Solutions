//O(n^2) time and O(n^2) space. DP solution.
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool> (n));
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = i; j < n; j++)
            {
                if(i == j)
                    dp[i][j] = true;
                else if(i+1 == j && s[i] == s[j])
                    dp[i][j] = true;
                else if(i+1 < n && j-1 >= 0 && s[i] == s[j] && dp[i+1][j-1] == true)
                    dp[i][j] = true;
            }
        }
        int maxlen = 1, maxi = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                if(dp[i][j] == true)
                {
                    if(maxlen < j - i + 1)
                    {
                        maxlen = j - i + 1;
                        maxi = i;
                    }
                }
            }
        }
        return s.substr(maxi, maxlen);
    }
};


//O(n^2) time and O(1) space using 2 pointer approach
class Solution {
private:
    void solve(int L, int R, string& s)
    {
        int n = s.size();
        while(L >= 0 && R < n && s[L] == s[R])
        {
            L--;
            R++;
        }
        if(maxlen < R - L - 1)
        {
            maxlen = R - L - 1;
            maxi = L + 1;
        }
    }
    
public:
    int maxi = 0, maxlen = 1;
    string longestPalindrome(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            solve(i, i, s);
            solve(i, i + 1, s);
        }
        return s.substr(maxi, maxlen);
    }
};
