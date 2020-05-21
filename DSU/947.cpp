class Solution {
public:
    struct hash_pair { 
    template <class T1, class T2> 
        size_t operator()(const pair<T1, T2>& p) const
        { 
            auto hash1 = hash<T1>{}(p.first); 
            auto hash2 = hash<T2>{}(p.second); 
            return hash1 ^ hash2; 
        } 
    }; 
    
    unordered_map<pair<int, int>, pair<int, int>, hash_pair> parent;
    unordered_map<pair<int, int>, int, hash_pair> sz;
    int components;
    int removeStones(vector<vector<int>>& stones) {
        components = stones.size();
        for(auto i: stones)
        {
            pair<int, int> p = {i[0], i[1]};
            parent[p] = p;
            sz[p] = 1;
        }
        for(int i = 0; i < stones.size(); i++)
        {
            for(int j = i+1; j < stones.size(); j++)
            {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    unify({stones[i][0], stones[i][1]}, {stones[j][0], stones[j][1]});
                    
                }
            }
        }
        return stones.size() - components;
    }
    
    pair<int, int> find(pair<int, int> v)
    {
        pair<int, int> root = v;
        while(root != parent[root])
            root = parent [root];
        
        while(v != root)
        {
            pair<int, int> next = parent[v];
            parent[v] = root;
            v = next;
        }
        return root;
    }
    
    void unify(pair<int, int> a, pair<int, int> b)
    {
        pair<int, int> root1 = find(a);
        pair<int, int> root2 = find(b);
        if(root1 == root2)
            return;
        components--;
        if(sz[root1] < sz[root2])
        {
            parent[root1] = root2;
            sz[root2] += sz[root1];
        }
        else
        {
            parent[root2] = root1;
            sz[root1] += sz[root2];
        }
    }
};
