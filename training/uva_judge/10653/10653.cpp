#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3, di[4]={1, 0, -1, 0}, dj[4]={0, 1, 0, -1};
int R, C, si, sj, ti, tj;
int adj[mxN][mxN], d[mxN][mxN];
bool vis[mxN][mxN];

bool isok(int i, int j){
	return i>=0 && i<R && j>=0 && j<C && !vis[i][j] && adj[i][j] == 0;
}

void init(){
	memset(vis, false, sizeof(vis));
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			d[i][j] = INT_MAX;
			adj[i][j] = 0;
		}
	}
}

int main()
{
	while(cin >> R >> C && (R || C)){
		init();
		int r;
		cin >> r;
		for(int i = 0, c, n, x; i < r; i++){
			cin >> c >> n;
			while(n--){
				cin >> x;
				adj[c][x] = 1;
			}
		}
		cin >> si >> sj >> ti >> tj;
		
		queue<array<int, 2>> qu;
		qu.push({si, sj});
		vis[si][sj] = 1;
		d[si][sj] = 0;
		while(qu.size()){
			array<int, 2> u = qu.front();
			qu.pop();
			for(int k = 0; k < 4; k++){
				int ni = di[k]+u[0], nj = dj[k]+u[1];
				if(isok(ni, nj) && d[ni][nj] >= d[u[0]][u[1]]+1){
					vis[ni][nj] = 1;
					d[ni][nj] = d[u[0]][u[1]]+1;
					qu.push({ni, nj});
				}
			}
		}
		cout << d[ti][tj] << '\n';
	}	
	return 0;
}


