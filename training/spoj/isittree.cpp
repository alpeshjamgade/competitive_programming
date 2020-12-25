#include <bits/stdc++.h>
using namespace std;
 
const int mxN = 1e5;
int n, m, p[mxN];
vector<int> adj[mxN];
bool vis[mxN];
 
void dfs(int u, int pu=-1){
	vis[u]=true;
	p[u] = pu;
	for(int v : adj[u]){
		if(pu == v){
			continue;
		}
		if(vis[v]){
			cout << "NO";
			exit(0);
		}
		else{
			dfs(v, u);
		}
	}
}
 
int main()
{
	cin >> n >> m;
	for(int i = 0,a ,b; i < m; i++){
		cin >> a >> b, a--, b--;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}	
	int cnt =0;
	memset(vis, false, sizeof(vis));
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			//cout << vis[i] << ' ';
			dfs(i);
			cnt++;
		}
	}
	if(cnt == 1){
		cout << "YES";
	}
	return 0;
}
