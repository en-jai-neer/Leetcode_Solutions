#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> parent, rnk;

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
	return a.second < b.second;
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
	if(rnk[root1] < rnk[root2])
		swap(root1, root2);
	parent[root2] = root1;
	if(rnk[root1] == rnk[root2])
		rnk[root1]++;
}

int32_t main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<pair<int, int>, int>> edges, result;
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({{a, b}, c});
	}
	for(int i = 0; i < 1e6; i++)
	{
		parent.push_back(i);
		rnk.push_back(1);
	}
	sort(edges.begin(), edges.end(), cmp);
	int cost = 0;
	for(auto edge: edges)
	{
		int x = edge.first.first;
		int y = edge.first.second;
		int w = edge.second;
		if(find(x) != find(y))
		{
			unify(x, y);
			cost += w;
			result.push_back(edge);
		}
	}
}
