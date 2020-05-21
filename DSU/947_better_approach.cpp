class Solution {
public:
    unordered_map<int, int> parent;
    unordered_map<int, int> sz;
    int components;
    int removeStones(vector<vector<int>>& stones) {
        for(auto i: stones)
        {
            unify(i[0], i[1]+10000);
        }
        return stones.size() - components;
    }

    int find(int v)
    {
        if(!parent.count(v))
        {
            parent[v] = v;
            sz[v] = 1;
            components++;
        }
        int root = v;
        while(root != parent[root])
            root = parent [root];
        
        while(v != root)
        {
            int next = parent[v];
            parent[v] = root;
            v = next;
        }
        return root;
    }
    
    void unify(int a, int b)
    {
        int root1 = find(a);
        int root2 = find(b);
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
