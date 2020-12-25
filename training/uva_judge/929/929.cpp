#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3, di[4]={1, 0, -1, 0}, dj[4]={0, 1, 0, -1};
int n, m, d[mxN][mxN];
int adj[mxN][mxN];
bool vis[mxN][mxN];

bool isok(int i, int j){
	return i>=0 && i<n && j>=0 && j<m && !vis[i][j];
}

void init(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			d[i][j] = INT_MAX;
			adj[i][j] = 0;
			vis[i][j] = 0;
		}
	}
}

//Dijkstra
int find_shortest_path(int si, int sj, int ti, int tj){
	priority_queue<array<int, 3>> pq;
	pq.push({0, si, sj});
	vis[si][sj] = 1;
	d[si][sj] = adj[si][sj];
	while(pq.size()){
		array<int, 3> u = pq.top();
		pq.pop();
		for(int k = 0; k < 4; k++){
			int ni = u[1]+di[k], nj = u[2]+dj[k];
			if(isok(ni, nj) && d[ni][nj] >= d[u[1]][u[2]]+adj[ni][nj]){
				vis[ni][nj] = 1;
				d[ni][nj] = d[u[1]][u[2]] + adj[ni][nj];
				pq.push({-d[ni][nj], ni, nj});
			}
		}
	}
	return d[ti][tj];
}

int main()
{
	int tt;
	cin >> tt;
	while(tt--){
		cin >> n >> m;
		init();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> adj[i][j];
			}
		}
		cout << find_shortest_path(0, 0, n-1, m-1) << '\n';
	}	
	return 0;
}
