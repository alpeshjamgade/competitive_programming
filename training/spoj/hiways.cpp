#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN = 1e5+5;
ll n, m, d[mxN], s, e;
vector<array<ll, 2>> adj[mxN];
bool vis[mxN];

int main()
{
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m >> s >> e;
		s--, e--;
		for(int i = 0; i < n; i++){
			adj[i].clear();
			d[i] = mxN;
			vis[i] = 0;
		}
		for(int i = 0, a, b, c; i < m; i++){
			cin >> a >> b >> c;
			a--, b--;
			adj[a].push_back({c, b});
			adj[b].push_back({c, a});
		}
		d[s] = 0;
		priority_queue<array<ll, 2>> pq;
		pq.push({0, s});
		while(!pq.empty()){
			array<ll, 2> u = pq.top();
			pq.pop();
			if(vis[u[1]])continue;
			vis[u[1]] = 1;
			for(array<ll, 2> v : adj[u[1]]){
				if(d[v[1]] > d[u[1]]+v[0]){
					d[v[1]] = d[u[1]]+v[0];
					pq.push({-d[v[1]], v[1]});
				}
			}
		}
		if(d[e] == mxN){
			cout << "NONE\n";
		}else{
			cout << d[e] << '\n';
		}
	}
	return 0;
}
