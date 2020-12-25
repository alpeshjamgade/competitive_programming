#include <bits/stdc++.h>
//#define debug

using namespace std;

const int mxN = 27;
string s, n;
int u, v, m;
vector<int> adj[mxN];
bool vis[mxN];

void dfs(int u){
	vis[u] = 1;
	for(int v : adj[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
}

void init(){
	for(int i = 0; i < m; i++){
		adj[i].clear();
	}
	memset(vis, 0, sizeof(vis));
}

void set_values(){
	u = int(s[0]-'A');
	v = int(s[1]-'A');
#ifdef debug
	cout << u << ' ' << v << '\n';
#endif
}

int main()
{
	ofstream fout("out");
	int tt;
	cin >> tt;
	while(tt--){
		cin >> n;
		m = (int)(n[0]-'A')+1;
		init();
		getline(cin, s);
		while(1){
			getline(cin, s);
			if(s.length() == 0){
				break;
			}
			set_values();
			adj[u].emplace_back(v);
			adj[v].emplace_back(u);
		}

		int cnt = 0;
		for(int i = 0; i < m; i++){
			if(!vis[i]){
				dfs(i); cnt++;
			}
		}	
		if(tt){
			cout << cnt << "\n\n";
		}
		else{
			cout << cnt << '\n';
		}
	}
	return 0;
}


