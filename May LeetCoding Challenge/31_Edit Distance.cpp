Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

class Solution {
private:
    int solve(int ind1, int ind2)
    {
        if(ind1 >= n1 && ind2 >= n2)
            return 0;
        if(ind1 >= n1)
            return n2 - ind2;
        if(ind2 >= n2)
            return n1 - ind1;
        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        int ans;
        if(word1[ind1] == word2[ind2])
        {
            ans = solve(ind1+1, ind2+1);
        }
        else
        {
            ans = min({solve(ind1, ind2+1), solve(ind1+1, ind2), solve(ind1+1, ind2+1)})+1;
        }
        return dp[ind1][ind2] = ans;
    }
    
public:
    string word1, word2;
    int n1, n2;
    vector<vector<int>> dp;
    int minDistance(string _word1, string _word2) {
        word1 = _word1;
        word2 = _word2;
        n1 = word1.size();
        n2 = word2.size();
        dp.clear();
        dp.resize(n1, vector<int> (n2, -1));
        return solve(0, 0);
    }
};
