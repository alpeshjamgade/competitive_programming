#include <bits/stdc++.h>
using namespace std;

const int mxN = 3e5;
int n, ans, c[mxN];
map<int, int> mp;
vector<int> adj[mxN];

void dfs(int u, int cu = 0){
    c[u] = cu;
	for(int v : adj[u]){
		if(v == pu) continue;
		dfs(v, cu^1);
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
	cout << min(mp[1], mp[0]);
	return 0;
}


