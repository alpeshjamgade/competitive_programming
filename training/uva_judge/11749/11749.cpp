#include <bits/stdc++.h>
using namespace std;

const int mxN = 500;
int n, m, mx_w, cnt;
vector<array<int, 2>> adj[mxN];
set<int> cmp;
bool vis[mxN];

void dfs(int u){
	vis[u] = 1;
	for(array<int, 2> vv : adj[u]){
		if(!vis[vv[0]] && vv[1] == mx_w){
			cmp.insert(u);
			cmp.insert(vv[0]);
			dfs(vv[0]);
		}	
	}
}

void init(){
	memset(vis, false, sizeof(vis));
	for(int i = 0; i < n; i++){
		adj[i].clear();
	}
	mx_w = INT_MIN;
}

int main()
{
	while(cin >> n >> m && (n || m)){
		init();
		for(int i = 0, u, v, w; i < m; i++){
			cin >> u >> v >> w; u--, v--;
			adj[u].push_back({v, w});
			mx_w = max(w, mx_w);
		}

		int ans = 0;
		for(int i = 0; i < n; i++){
			if(!vis[i]){
				cmp.clear();
				dfs(i);
				for(int a : cmp){
					cout << a << ' ';
				}
				ans = max((int)cmp.size(), ans);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

