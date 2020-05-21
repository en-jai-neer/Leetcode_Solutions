class Solution {
    
public:
    vector<int> parent, sz;
    int components, n;
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        components = 4*n*n;
        vector<int> p(components);
        vector<int> s(components);
        parent = p;
        sz = s;
        init();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '/')
                {
                    unify(pos(i, j, 3), pos(i, j, 0));
                    unify(pos(i, j, 1), pos(i, j, 2));
                }
                else if(grid[i][j] == '\\')
                {
                    unify(pos(i, j, 0), pos(i, j, 1));
                    unify(pos(i, j, 2), pos(i, j, 3));
                }
                else
                {
                    unify(pos(i, j, 0), pos(i, j, 1));
                    unify(pos(i, j, 2), pos(i, j, 3));
                    unify(pos(i, j, 0), pos(i, j, 2));
                }
                if(i-1 >= 0)
                {
                    unify(pos(i, j, 0), pos(i-1, j, 2));
                }
                if(i+1 < n)
                {
                    unify(pos(i, j, 2), pos(i+1, j, 0));
                }
                if(j-1 >= 0)
                {
                    unify(pos(i, j, 3), pos(i, j-1, 1));
                }
                if(j+1 < n)
                {
                    unify(pos(i, j, 1), pos(i, j+1, 3));
                }
            }
        }
        return components;
    }
    
    void init()
    {
        for(int i = 0; i < components; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
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
        if(root1 == root2)
            return;
        components--;
        if(sz[root1] < sz[root2])
        {
            sz[root2] += sz[root1];
            parent[root1] = root2;
        }
        else
        {
            sz[root1] += sz[root2];
            parent[root2] = root1;
        }
    }
    
    int pos(int i, int j, int k)
    {
        return (i*n + j)*4 + k;
    }
};
