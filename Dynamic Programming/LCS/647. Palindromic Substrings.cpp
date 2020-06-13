//O(n^2) time ans O(1) space. 2 pointers approach.
class Solution {
private:
    int solve(int L, int R, string& s)
    {
        int n = s.size();
        int cnt = 0;
        while(L >= 0 && R < n && s[L] == s[R])
        {
            cnt++;
            L--;
            R++;
        }
        return cnt;
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans += solve(i, i, s);
            ans += solve(i, i+1, s);
        }
        return ans;
    }
};

//O(n^2) time ans O(n^2) space. DP approach.
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool> (n));
        int ans = 0;
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = i; j < n; j++)
            {
                if(i == j || (j == i+1 && s[i] == s[j]))
                {
                    dp[i][j] = true;
                    ans++;
                }
                else if(i+1 < n && j-1 >= 0 && s[i] == s[j] && dp[i+1][j-1] == true)
                {
                    dp[i][j] = true;
                    ans++;
                }
            }
        }
        return ans;
    }
};
