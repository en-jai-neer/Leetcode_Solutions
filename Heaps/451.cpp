class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        auto cmp = [](auto &a, auto &b)
        {
            return a.second < b.second;
        };
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        for(char c: s)
        {
            mp[c]++;
        }
        for(auto i: mp)
        {
            pq.push({i.first, i.second});
        }
        string ans = "";
        while(!pq.empty())
        {
            pair<char, int> p = pq.top();
            string s(p.second, p.first);
            ans += s;
            pq.pop();
        }
        return ans;
    }
};
