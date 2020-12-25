#include <bits/stdc++.h>
using namespace std;


const int mxN = 1e5+5;
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
int main()
{

	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 0; i <= n; i++){
			adj[i].clear();
		}
		ts.clear();
		for(int i = 0, u, v; i < m; i++){
			cin >> u >> v;
			adj[u].push_back(v);
		}
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i++){
			if(!vis[i]){
				dfs(i);
			}
		}
		memset(vis, false, sizeof(vis));
		reverse(ts.begin(), ts.end());
		int cnt = 0;
		for(int i = 0; i < n; i++){
			int u = ts[i];
			if(!vis[u]){
				dfs(u); cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
