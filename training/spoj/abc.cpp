#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3, di[8]={-1, -1, -1, 0, 0, 1, 1, 1}, dj[8]={-1, 0, 1, -1, 1, -1, 0, 1};
int n, m;
string s[mxN];
int dp[mxN][mxN];


bool isok(int i, int j){
	return i>=0&&i<n&&j>=0&&j<m;
}

int dfs(int i, int j, char letter){
	if(dp[i][j] != -1)
		return dp[i][j];
	int cnt = 1;
	for(int k = 0; k < 8; k++){
		int ni = i+di[k], nj = j+dj[k];
		if(isok(ni, nj) && letter == s[ni][nj]){
			cnt = max(cnt, 1+dfs(ni, nj, letter+1));
		}
	}
	dp[i][j] = cnt;
	return cnt;
}

int main()
{
	int __case = 1;
	while(1){
		cin >> n >> m;
		if(n == 0 && m == 0){
			break;
		}
		for(int i = 0; i < n; i++){
			cin >> s[i];	
		}
		memset(dp, -1, sizeof(dp));
		int mx = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(isok(i, j) && s[i][j] == 'A'){
					mx = max(dfs(i, j, s[i][j]+1), mx);
				}
			}
		}

		cout << "Case " << __case << ": " << mx<< '\n';
		__case++;
	}
	return 0;
}


