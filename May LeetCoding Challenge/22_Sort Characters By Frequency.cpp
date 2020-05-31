Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.


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
