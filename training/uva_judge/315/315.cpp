#include <bits/stdc++.h>
using namespace std;

const int mxN = 100;
int n, m, tin[mxN], low[mxN], timer, cnt;
bool vis[mxN];
string in;
vector<int> adj[mxN];
set<int> ans;

void dfs(int u, int pu = -1){

	vis[u] = 1;
	tin[u] = low[u] = timer++;
	int children = 0;
	for(int v : adj[u]){
		if(v == pu) continue;
		if(vis[v]){
			low[u] = min(low[u], tin[v]);
		}else{
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] >= tin[u] && pu != -1){
				ans.insert(u);
				cnt++;
			}
			++children;
		}
	}
	if(pu == -1 && children > 1){
		ans.insert(u);
		cnt++;
	}
}

void init(){
	timer = 0;
	cnt = 0;
	ans.clear();
	memset(vis, false, sizeof(vis));
	memset(tin, -1, sizeof(tin));
	memset(low, -1, sizeof(low));
	for(int i = 0; i < n; i++){
		adj[i].clear();
	}
}

int main()
{
	while(1){
		cin >> n;
		if(n == 0){
			break;
		}
		init();
		cin.ignore();
		while(1){
			getline(cin, in);
			stringstream ss(in);
			int u, v;
			ss >> u;
			if(u == 0){
				break;
			}
			while(ss >> v){
				adj[u-1].emplace_back(v-1);
				adj[v-1].emplace_back(u-1);
			}
		}
		for(int i = 0; i < n; i++){
			if(!vis[i]) dfs(i);
		}
		cout << ans.size() << '\n';
	}	
	return 0;
}

