#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3;
int n, m;
string in;
map<string, int> node_id;
vector<int> adj[mxN], adjr[mxN], ts;
bool vis[mxN];

void dfs1(int u){
	vis[u] = 1;
	for(int v : adj[u]){
		if(!vis[v]){
			dfs1(v);
		}
	}
	ts.push_back(u);
}

void dfs2(int u){
	vis[u] = 1;
	for(int v : adjr[u]){
		if(!vis[v]){
			dfs2(v);
		}
	}
}

// Kosaraju's Algorithm

int SCC_count(){
	
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			dfs1(i);
		}
	}
	reverse(ts.begin(), ts.end());
	memset(vis, false, sizeof(vis));
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(!vis[ts[i]]){
			dfs2(ts[i]), cnt++;
		}
	}
	return cnt;
}

void init(){
	memset(vis, false, sizeof(vis));
	ts.clear();
	node_id.clear();
	for(int i = 0; i < n; i++){
		adj[i].clear();
		adjr[i].clear();
	}
}

int main()
{
	while(cin >> n >> m && (n || m)){
		init();
		cin.ignore();
		int id = 0;
		for(int i = 0; i < n; i++){
			getline(cin, in);
			if(node_id.find(in) == node_id.end()){
				node_id[in] = id++;
			}
		}
		for(int i = 0, u, v; i < m; i++){
			getline(cin, in);
			u = node_id[in];
			getline(cin, in);
			v = node_id[in];
			adj[u].emplace_back(v);
			adjr[v].emplace_back(u);
		}
		cout << SCC_count() << '\n';
	}	
	return 0;
}


