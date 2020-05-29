Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        if(s.size() == 0)
            return -1;
        for(char c: s)
        {
            mp[c]++;
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(mp[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
