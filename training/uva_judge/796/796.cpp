#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3;
int n, m, tin[mxN], low[mxN], timer;
vector<int> adj[mxN];
string in;
set<array<int, 2>> ans;
bool vis[mxN];

void dfs(int u,  int pu = -1){
	vis[u] = 1;
	tin[u] = low[u] = timer++;
	for(int v : adj[u]){
		if (v == pu) continue;
		if (vis[v]){
			low[u] = min(low[u], tin[v]);
		}else{
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > tin[u]){
				array<int, 2> tmp={u, v};
				sort(tmp.begin(), tmp.end());
				ans.insert(tmp);
			}
		}
	}
}

void init(){
	ans.clear();
	timer = 0;
	for(int i = 0; i < n; i++)
		adj[i].clear();

	memset(vis, false, sizeof(vis));
	memset(tin, -1, sizeof(tin));
	memset(low, -1, sizeof(low));
}

int main()
{
	ofstream fout("out");
	while(cin >> n){
		init();
		int u, v;
		for(int i = 0; i < n; i++){
			cin >> u;
			cin.ignore();
			cin.ignore();
			cin >> m;
			cin.ignore();
			while(m--){
				cin >> v;
				adj[u].emplace_back(v);
				adj[v].emplace_back(u);
			}
		}
		for(int i = 0; i < n; i++){
			if(!vis[i]) dfs(i);
		}
		printf("%d critical links\n", (int)ans.size());
		for(array<int, 2> a : ans){
			cout << a[0] << " - " << a[1] << '\n';
		}
		cout << "\n";
	}
	return 0;
}


