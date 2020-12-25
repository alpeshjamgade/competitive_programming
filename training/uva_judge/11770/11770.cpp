#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e4;
int n, m;
vector<int> adj[mxN], ts;
bool vis[mxN];

void dfs(int u){
	vis[u] = 1;
	for(int v : adj[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
	ts.push_back(u);
}

void init(){
	memset(vis, false, sizeof(vis));
	ts.clear();
	for(int i = 0; i < n; i++){
		adj[i].clear();
	}
}

int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n >> m;
		init();
		for(int j = 0, u, v; j < m; j++){
			cin >> u >> v, u--, v--;
			adj[u].emplace_back(v);
		}

		// doing topological sort;
		for(int j = 0; j < n; j++){
			if(!vis[j]) dfs(j);
		}
		reverse(ts.begin(), ts.end());

		memset(vis, false, sizeof(vis));	
		int cnt = 0;
		for(int j = 0; j < n; j++){
			if(!vis[ts[j]]) dfs(ts[j]), cnt++;
		}
		cout <<"Case " << i << ": " << cnt << '\n';
	}	
	return 0;
}

