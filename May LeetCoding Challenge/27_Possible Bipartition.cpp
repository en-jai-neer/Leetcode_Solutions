Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Constraints:

1 <= N <= 2000
0 <= dislikes.length <= 10000
dislikes[i].length == 2
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].

class Solution {
private:
    void dfs(vector<int> adj[], int s)
    {
        vis[s] = true;
        for(int i = 0; i < adj[s].size(); i++)
        {
            int v = adj[s][i];
            if(vis[v] == false)
            {
                color[v] = 1 - color[s];
                dfs(adj, v);
            }
            else if(color[v] == color[s])
            {
                ans = false;
            }
        }
    }
    
public:
    vector<bool> vis;
    vector<int> color;
    bool ans = true;
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vis.clear();
        vis.resize(N+1, false);
        color.clear();
        color.resize(N+1, -1);
        vector<int> adj[N+1];
        for(int i = 0; i < dislikes.size(); i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        color[1] = 0;
        for(int i = 1; i <= N; i++)
        {
            if(vis[i] == false)
                dfs(adj, i);
        }
        //for()
        return ans;
    }
};
