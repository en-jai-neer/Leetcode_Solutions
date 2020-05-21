class Solution {
public:
    vector<int> parent, sz;
    int islands;
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0)
            return 0;
        int m = grid[0].size();
        parent.resize(n*m, -1);
        sz.resize(n*m);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    if(i-1 >= 0 && grid[i-1][j] == '1')
                        unify(i*m+j, (i-1)*m+j);
                    if(j-1 >= 0 && grid[i][j-1] == '1')
                        unify(i*m+j, i*m+j-1);
                    islands++;
                }
            }
        }
        return islands;
    }
    
    int find(int v)
    {
        if(parent[v] == -1)
        {
            parent[v] = v;
            sz[v] = 1;
        }
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
        islands--;
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
