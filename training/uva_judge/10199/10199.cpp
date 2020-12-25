#include <bits/stdc++.h>
using namespace std;

const int mxN = 100;
int n, m, tin[mxN], low[mxN], timer;
string in, in2;
vector<int> adj[mxN];
map<string, int> node_id;
map<int, string> node_name;
set<string> ans;
bool vis[mxN];

void dfs(int u, int pu = -1){
	vis[u] = 1;
	tin[u] = low[u] = timer++;
	int children = 0;
	for(int v : adj[u]){
		if(v == pu) continue;
		if(vis[v]){
			low[u] = min(low[u], tin[v]);
		}else{
			dfs(v,u);
			low[u] = min(low[u], low[v]);
			if(low[v] >= tin[u] && pu != -1){
				ans.insert(node_name[u]);
			}
			children++;
		}	
	}
	if(pu == -1 && children > 1){
		ans.insert(node_name[u]);
	}
}

void init(){
	memset(vis, false, sizeof(vis));
	memset(tin, -1, sizeof(tin));
	memset(low, -1, sizeof(low));
	for(int i = 0; i < n; i++){
		adj[i].clear();
	}
	node_id.clear();
	node_name.clear();
	ans.clear();
	timer = 0;
}

int main()
{
	ofstream fout("out");
	int __map = 1;
	cin >> n;
	while(1){
		if(n == 0){
			break;
		}
		init();
		int id = 0;
		for(int i = 0; i < n; i++){
			cin >> in;
			node_id[in] = id;
			node_name[id] = in;
			id++;
		}
		cin >> m;
		for(int i = 0; i < m; i++){
			cin >> in >> in2;
			adj[node_id[in]].emplace_back(node_id[in2]);
			adj[node_id[in2]].emplace_back(node_id[in]);
		}
		for(int i = 0; i < n; i++){
			if(!vis[i]) dfs(i);
		}
		printf("City map #%d: %d camera(s) found\n", __map, (int)ans.size());
		fout << "City map #" << __map++ <<": " << (int)ans.size() << " camera(s) found\n";
		for(string a : ans){
			cout << a << '\n';
			fout << a<< '\n';
		}
		cin >> n;
		if(n == 0){
			break;
		}
		cout << '\n';
		fout << '\n';
	}
	return 0;
}

