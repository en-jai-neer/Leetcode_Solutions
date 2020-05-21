class Solution {
public:
    vector<int> parent, rank;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i = 0; i < 1001; i++)
            parent.push_back(i);
        rank.resize(1001);
        vector<int> ans;
        for(auto edge :edges)
        {
            int x = edge[0];
            int y = edge[1];
            if(find(x) == find(y))
            {
                ans.push_back(x);
                ans.push_back(y);
                return ans;
            }
            else
            {
                unify(x, y);
            }
        }
        return ans;
    }
    
    int find(int v)
    {
        int root = v;
        while(root != parent[root])
            root = parent[root];
        
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
        if(rank[root1] < rank[root2])
        {
            parent[root1] = root2;
            rank[root2]++;
        }
        else
        {
            parent[root2] = root1;
            rank[root1]++;
        }
    }
};
