#include <bits/stdc++.h>
using namespace std;

const int mxN = 100;
int t, n, m, cnt;
vector<int> adj[mxN];
bool vis[mxN];

void dfs(int u){
	vis[u] = 1;
	for(int v : adj[u]){
		if(!vis[v])
			dfs(v);
	}
	cnt++;
}

void init(){
	for(int i = 0; i < n; i++){
		adj[i].clear();
	}
	cnt = 0;
	memset(vis, 0, sizeof(vis));
}

int main()
{
	while(cin >> n && n){
		init();
		for(int i = 0, u, v; i < n; i++){
			cin >> u;
			for(int j = 0; j < u; j++){
				cin >> v, v--;
				adj[i].emplace_back(v);
			}
		}
		int index = INT_MAX;
		int d = -1;
		for(int i = 0; i < n; i++){
			memset(vis, 0, sizeof(vis));
			cnt = 0;
			dfs(i);
			if(cnt > d){
				d = cnt;
				index = i;
			}else if(cnt == d){
				index = min(i, index);
			}	
		}
		cout << index+1 << '\n';
	}	
	return 0;
}
	
