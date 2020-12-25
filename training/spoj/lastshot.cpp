#include <bits/stdc++.h>
using namespace std;

const int mxN=1e4;
int n, m, ans, cnt;
vector<int> adj[mxN];
bool vis[mxN];

void dfs(int u){
	cnt++;
	vis[u] = 1;
	//cout << u << ' ';
	for(int v : adj[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
}

int main()
{
	cin >> n >> m;
	for(int i = 0, a, b; i < m; i++){
		cin >> a >> b;
		a--, b--;
		adj[a].emplace_back(b);
	}
	
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			cnt = 0;
			memset(vis, false, sizeof(vis));
			dfs(i);
			ans = max(cnt, ans);
		}
	}
	cout << ans;
	return 0;
}
