#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e2;
int n, m, c[mxN];
vector<int> adj[mxN];

bool isBipartite(int u, int cu = 0){
	if(c[u] != -1){
		if(cu^c[u]){
			return false;
		}
		return true;
	}
	c[u] = cu;
	bool ok = 1;
	for(int v : adj[u]){
		ok &= isBipartite(v, cu^1);
	}
	return ok;
}

void init(){
	memset(c, -1, sizeof(c));
	for(int i = 0; i < n; i++){
		adj[i].clear();
	}
}

int main()
{
	while(scanf("%d %d", &n, &m) && n){
		init();
		for(int i = 0, u, v; i < m; i++){
			cin >> u >> v;
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}

		bool ok = 1;
		for(int i = 0; i < n; i++){
			if(c[i] < 0){
				ok &= isBipartite(i);
			}
		}
		cout << (!ok?"NOT BICOLORABLE.":"BICOLORABLE.") << '\n';
	}	
	return 0;
}
