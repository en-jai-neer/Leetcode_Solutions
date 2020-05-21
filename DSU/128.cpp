class Solution {
public:
    unordered_map<int, int> parent, sz;
    int longestConsecutive(vector<int>& nums) {
        for(int i: nums)
        {
            parent[i] = i;
            sz[i] = 1;
        }
        for(int i: nums)
        {
            if(parent.count(i-1))
            {
                unify(i, i-1);
            }
            if(parent.count(i+1))
            {
                unify(i, i+1);
            }
        }
        int ans = 0;
        for(auto i: sz)
        {
            ans = max(ans, i.second);
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
        if(root1 == root2)
            return;
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
