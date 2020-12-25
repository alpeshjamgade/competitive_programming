#include <bits/stdc++.h>
//#define debug
using namespace std;

const int mxN = 1e3;
int n, m;
vector<int> adj[mxN];
map<int, int> node_id;
vector<array<int, 2>> edges;
bool vis[mxN];

int bfs(int node, int time){
	memset(vis, false, sizeof(vis));
	queue<array<int, 2>> qu;
	qu.push({node, time});
	vis[node] = 1;
	while(qu.size()){
		array<int, 2> u = qu.front();
		qu.pop();
		if(u[1]){
			for(int v : adj[u[0]]){
				if(!vis[v]){
					qu.push({v, u[1]-1});
					vis[v] = 1;
				}
			}
		}
	}
	// now counting the NOT_VISITED nodes;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			cnt++;
		}
	}
	return cnt;
}

void init(){
	edges.clear();
	node_id.clear();
	memset(vis, false, sizeof(vis));
	for(int i = 0; i < n; i++){
		adj[i].clear();
	}
}

void set_adj(){
	for(auto it : edges){
		adj[it[0]].emplace_back(it[1]);
		adj[it[1]].emplace_back(it[0]);
	}
}

int main()
{
	int __case = 1;
	while(cin >> m){
		int id = 0;
		init();
		for(int i = 0, u, v; i < m; i++){
			cin >> u >> v;
			if(node_id.find(u) == node_id.end()){
#ifdef debug
				cout << u << " is mapped to " << id << '\n';
#endif
				node_id[u] = id++;
			}
			if(node_id.find(v) == node_id.end()){
#ifdef debug
				cout << v << " v is mapped to " << id << '\n';
#endif
				node_id[v] = id++;
			}
			u = node_id[u], v = node_id[v];
			edges.push_back({u, v});
		}
		n = node_id.size();
		set_adj();
#ifdef debug
		cout << "printing adjacency list\n";
		for(int i = 0; i < n; i++){
			cout << i << "->";
			for(int u : adj[i]){
				cout << u << ' ';
			}
			cout << '\n';
		}
#endif
		int node, time;
		while(cin >> node >> time && (node || time)){
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",__case++, bfs(node_id[node], time), node, time);
		}
	}	
	return 0;
}

