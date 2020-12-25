#include <bits/stdc++.h>
//#define debug
using namespace std;
ofstream fout("out");
const int mxN = 26;
int n, m, tin[mxN], low[mxN], timer;
vector<int> adj[mxN], adjr[mxN], res, ts;
set<int> ans;
map<string, int> node_id;
map<int, string> node_name;
bool vis[mxN];

void tarjanSCC(int u){
	vis[u] = 1;
	tin[u] = low[u] = timer++;
	res.push_back(u);
	for(int v : adj[u]){
		if(tin[v] == -1){
			tarjanSCC(v);
			low[u] = min(low[u], low[v]);
		}
		else if(vis[v]){
			low[u] = min(low[u], tin[v]);
		}
	}
	if(low[u] == tin[u]){
		while(1){
			int v = res.back(); res.pop_back(), vis[v] = 0;
			if(u == v){
				cout << node_name[v] << '\n';
				break;
			}else{
				cout << node_name[v] << ", ";
			}
		}
	}
}

void dfs1(int u){
	vis[u] = 1;
	for(int v : adj[u]){
		if(!vis[v]){
			dfs1(v);
		}
	}
	ts.push_back(u);
}

void dfs(int u){
	vis[u] = 1;
	for(int v : adjr[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
	cout << node_name[u] << ' ';
}

void kosarajuSCC(){
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			dfs1(i);
		}
	}
	memset(vis, false, sizeof(vis));
	reverse(ts.begin(), ts.end());
	for(int i = 0; i < n; i++){
		if(!vis[ts[i]]){
			dfs(ts[i]);
			cout << '\n';
		}
	}
}

void init(){
	for(int i = 0; i < n; i++){
		adj[i].clear();
		adj[i].clear();
	}
	ts.clear();
	ans.clear();
	node_id.clear();
	node_name.clear();
	timer = 0;
	res.clear();
	memset(vis, false, sizeof(vis));
	memset(tin, -1, sizeof(tin));
	memset(low, -1, sizeof(low));
}

int main()
{
	int __case = 1;
	while(cin >> n >> m && (n||m)){
		init();
		int id = 0;
		string a, b;
		for(int i = 0; i < m; i++){
			cin >> a >> b;
			if(node_id.find(a) == node_id.end()){
				node_id[a] = id;
				node_name[id] = a;
				id++;
			}
			if(node_id.find(b) == node_id.end()){
				node_id[b] = id;
				node_name[id] = b;
				id++;
			}
			adj[node_id[a]].emplace_back(node_id[b]);
			adjr[node_id[b]].emplace_back(node_id[a]);
		}
#ifdef debug
		for(int i = 0; i < n; i++){
			cout << i << " is mapped to " << node_name[i] << '\n';
		}
#endif
		printf("Calling circles for data set %d:\n", __case++);
	/*for(int i = 0; i < n; i++){
			if(tin[i] == -1){
				tarjanSCC(i);
			}
		}*/
		kosarajuSCC();
		if(__case != 1){
			cout << '\n';
		}
	}	
	return 0;
}

