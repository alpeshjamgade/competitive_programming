#include <bits/stdc++.h>
using namespace std;

const int mxN = 100, di[8]={-1, -1, -1, 0, 0, 1, 1, 1}, dj[8]={-1, 0, 1, -1, 1, -1,0, 1};
int n, m;
string s[mxN];

bool isok(int i, int j){
    return i>=0 && i<n && j>=0 && j<m && s[i][j]=='@';
}

void dfs(int i, int j){
    s[i][j] = '*';
    for(int k = 0; k < 8; k++){
        int ni = i+di[k], nj = j+dj[k];
	if(isok(ni, nj)){
	    dfs(ni, nj);
	}
    }
}
int main()
{
    while(scanf("%d %d", &n, &m) &&(n||m)){
	for(int i = 0; i < n; i++){
	    cin >> s[i];
	}

	int cnt = 0;
	for(int i = 0; i < n; i++){
	    for(int j = 0; j < m; j++){
		if(isok(i, j)){
		    dfs(i, j); cnt++;
		}
	    }
	}
	cout << cnt << '\n';
    }
    return 0;
}
