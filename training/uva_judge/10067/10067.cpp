#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
int n, m, s[4], t[4], d[mxN];
vector<int> adj[mxN];
bool vis[mxN];

bool isok(int i, int j, int k, int l){
	int tmp = l + k*10 + j*100 + i*1000;
	return i>=0 && i<=9 && j>=0 && j<=9 && k>=0 && k<=9 && l>=0 && l<=9 && !vis[tmp];
}

void init(){
	memset(vis, false, sizeof(vis));
	memset(d, -1, sizeof(d));
}

int main()
{
	int tt;
	cin >> tt;
	while(tt--){
		init();
		for(int i = 0; i < 4; i++){
			cin >> s[i];
		}
		for(int i = 0; i < 4; i++){
			cin >> t[i];
		}
		cin >> n;
		for(int i = 0; i < n; i++){
			int d1, d2, d3, d4;
			cin >> d1  >> d2 >> d3 >> d4;
			int tmp = d4 + d3*10 + d2*100 + d1*1000;
			vis[tmp] = 1;
		}
		queue<array<int, 4>> qu;
		qu.push({s[0], s[1], s[2], s[3]});
		int ss = s[3] + s[2]*10 + s[1]*100 + s[0]*1000;
		int tt = t[3] + t[2]*10 + t[1]*100 + t[0]*1000;
		vis[ss] = 1;
		d[ss] = 0;

		while(qu.size()){
			array<int, 4> u = qu.front();
			int uu = u[3] + u[2]*10 + u[1]*100 + u[0]*1000;
			qu.pop();
			for(int i = -1; i < 2; i++){
				for(int j = -1; j < 2; j++){
					for(int k = -1; k < 2; k++){
						for(int l = -1; l < 2; l++){
							int ni = u[0]+i, nj =u[1]+j, nk=u[2]+k, nl=u[3]+l;
							int vv = nl + nk*10 + nj*100 + ni*1000;
							if(isok(ni, nj, nk, nl) && d[vv] == -1){
								qu.push({ni, nj, nk, nl});
								d[vv] = d[uu]+1;
								vis[vv] = 1; 
							}
						}
					}
				}
			}
		}
		if(d[tt] == INT_MAX){
			cout << -1 << '\n';
		}else
		cout << d[tt] << '\n';
	}	
	return 0;
}


