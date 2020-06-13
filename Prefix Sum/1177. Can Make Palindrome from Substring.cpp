class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        
        vector<vector<int>> pref(n+1, vector<int> (26));
        for(int i = 0; i < n; i++)
        {
            pref[i+1] = pref[i];
            pref[i+1][s[i]-'a']++;
        }
        
        vector<bool> ans;
        for(auto q: queries)
        {
            int x = q[0];
            int y = q[1];
            int k = q[2];
            int odd = 0;
            for(int i = 0; i < 26; i++)
            {
                int t = pref[y+1][i] - pref[x][i];
                if(t % 2 == 1)
                    odd++;
            }
            odd /= 2;
            ans.push_back(odd <= k);
        }
        
        return ans;
    }
};
