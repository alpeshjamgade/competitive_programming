#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
int n, d[mxN], ans;
vector<int> adj[mxN];


void dfs(int u, int pu = -1){
	for(int v : adj[v]){
		if(v == pu){
			continue;
		}
		dfs(v, u);
		ans = max(d[u]+d[v]+1, ans);
		d[v] = max(d[u], d[v]+1);
	}
}

int main()
{
	cin >> n;
	for(int i = 1, a, b; i < n; i++){
		cin >> a >> b, a--, b--;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	dfs(0);
	cout << ans;
	return 0;
}


