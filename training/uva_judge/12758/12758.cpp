#include <bits/stdc++.h>
using namespace std;

const int mxN = 200, di[6]={-1, -1, 0, 0, 1, 1}, dj[6]={-1, 0, -1, 1, 0, 1};
int n;
string s[mxN];
bool vis[mxN][mxN];

bool isok(int i, int j){
	return i>=0 && i<n && j>=0 && j< n && !vis[i][j];
}

void dfs(int i, int j){
	vis[i][j] = 1; 
	for(int k = 0; k < 6; k++){
		int ni = i+di[k], nj = j+dj[k];
		if(isok(ni, nj) && s[ni][nj] == s[i][j]){
			dfs(ni, nj);
		}
	}
}

int main()
{	
	ofstream fout("out");
	int t = 1;
	while(cin >> n  && n){
		for(int i = 0; i < n; i++){
			cin >> s[i];
		}
		bool ok = 0;
		memset(vis, false, sizeof(vis));
		for(int i = 0; i < n; i++){
			if(s[i][0] == 'w'){
				dfs(i, 0);
			}
		}
		for(int i = 0; i < n; i++){
			if(vis[i][n-1]){
				ok = 1;
				break;
			}
		}
		cout << t++ << ' ' << (ok?'W':'B') << '\n';
	}	
	return 0;
}


