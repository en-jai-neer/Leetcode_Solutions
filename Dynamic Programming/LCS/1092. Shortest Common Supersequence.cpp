//Recursive by finding the lcs. O(n*m*min(n,m)) time complexity and O(n*m*min(n,m)) space complexity
class Solution {
private:
    string lcs(string& s, string& t) {
        int n = s.size();
        int m = t.size();
        vector<vector<string>> dp(n + 1, vector<string>(m + 1, ""));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (s[i] == t[j])
                    dp[i + 1][j + 1] = dp[i][j] + s[i];
                else
                {
                    if(dp[i + 1][j].size() > dp[i][j + 1].size())
                        dp[i + 1][j + 1] = dp[i + 1][j];
                    else
                        dp[i + 1][j + 1] = dp[i][j + 1];
                }
            }
        }
        return dp[n][m];
    }
        
public:
    string shortestCommonSupersequence(string s, string t) {
        string x = lcs(s, t);
        int n = s.size();
        int m = t.size();
        string ans = "";
        int i = 0, j = 0;
        for(char c: x)
        {
            while(i < n && s[i] != c)
            {
                ans += s[i];
                i++;
            }
            while(j < m && t[j] != c)
            {
                ans += t[j];
                j++;
            }
            ans += c;
            i++;
            j++;
        }
        if(i != n)
            ans += s.substr(i);
        if(j != m)
            ans += t.substr(j);
        return ans;
    }
};

//without finding the lcs. O(n*m*(n+m)) time complexity and O(n*m*(n+m)) space complexity
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<string>> dp(n+1, vector<string> (m+1, ""));
        for(int i = 1; i <= n; i++)
            dp[i][0] = s.substr(0, i);
        for(int j = 1; j <= m; j++)
            dp[0][j] = t.substr(0, j);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(s[i] == t[j])
                    dp[i+1][j+1] = dp[i][j] + s[i];
                else
                {
                    if(dp[i][j+1].size() < dp[i+1][j].size())
                        dp[i+1][j+1] = dp[i][j+1] + s[i];
                    else
                        dp[i+1][j+1] = dp[i+1][j] + t[j];
                }
            }
        }
        return dp[n][m];
    }
};

//Finding lcs in O(n*m) time and space. Then constructing the scs using the lcs.
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(s[i] == t[j])
                    dp[i+1][j+1] = dp[i][j] + 1;
                else
                {
                   dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        int i = n-1, j = m-1;
        string lcs = "";
        while(i >= 0 && j >= 0)
        {
            if(s[i] == t[j])
            {
                lcs += s[i];
                i--;
                j--;
            }
            else
            {
                if(dp[i+1][j] > dp[i][j+1])
                    j--;
                else
                    i--;
            }
        }
        reverse(lcs.begin(), lcs.end());
        string ans = "";
        i = 0, j = 0;
        for(char c: lcs)
        {
            while(s[i] != c)
            {
                ans += s[i];
                i++;
            }
            while(t[j] != c)
            {
                ans += t[j];
                j++;
            }
            ans += c;
            i++;
            j++;
        }
        while(i < n)
        {
            ans += s[i];
            i++;
        }
        while(j < m)
        {
            ans += t[j];
            j++;
        }
        return ans;
    }
};
