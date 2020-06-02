class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(string s: words)
            mp[s]++;
        
        auto cmp = [&](string a, string b)
        {
            if(mp[a] == mp[b])
                return a > b;
            return mp[a] < mp[b];
        };
        priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
        for(auto it: mp)
        {
            pq.push(it.first);
        }
        vector<string> ans;
        for(int i = 0; i < k; i++)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
