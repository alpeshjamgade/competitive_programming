#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
vector<int> adj[mxN];
int n, m, c[mxN];

bool isBipartite(int u){
	bool res = 1;
	for(int v : adj[u]){
		if(c[v] != 0){
			if(c[v] == c[u]){
				return false;
			}
		}
		else{
			c[v] = -c[u];
			res &= isBipartite(v);
		}
	}
	return res;
}

int main()
{
	int t;
	cin >> t;
	for(int k = 1; k <= t; k++){
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			c[i] = 0;
			adj[i].clear();
		}
		for(int i = 0, a, b; i < m; i++){
			cin >> a >> b, a--, b--;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		
		bool ok = 1;
		for(int i = 0; i < n; i++){
			if(c[i] == 0){
				c[i] = 1;
				ok &= isBipartite(i);
			}
		}
		cout << "Scenario #" << k << ":\n";
		if(ok){
			cout << "No suspicious bugs found!";
		}else{
			cout << "Suspicious bugs found!";
		}
		cout << '\n';
	}
	return 0;
}
