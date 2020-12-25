#include <bits/stdc++.h>
using namespace std;

const int mxN = 10;
int n, m, si, sj, ti, tj;
int grid[mxN][mxN];
bool vis[mxN][mxN];

bool isok(int i, int j){
	return i>=0 && i<6 && j>=0 && j<6 && !vis[i][j];
}

int main()
{
	while(cin >> si >> sj && (si || sj)){
		cin >> ti >> tj;
		for(int i = 0, x, y; i < 3; i++){
			cin >> x >> y;
		}
		queue<array<int, 2>> qu;
		qu.push({si, sj});
		vis[si][sj] = 1;
		d[si][sj] = 0;
		while(qu.size()){
			int u = qu.front();
			qu.pop();
			for(int k = 0; k < 4; k++){
				int ni = di[k]+u[0], nj =dj[k]+u[1];
				if(isok(ni, nj)){
					qu.push(ni, nj);
					vis[ni][nj] = 1;
				}
			}
		}
		cout << d[ti][tj] << '\n';
	}	
	return 0;
}

