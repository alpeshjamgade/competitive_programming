#include <bits/stdc++.h>
using namespace std;

const int mxN = 100, di[8]={1, 0, -1, 0, -1, -1, 1, 1}, dj[8]={0, 1, 0, -1, -1, 1, -1, 1};
int n, m, ans;
vector<int> disjoint_sets(10000);
string s[mxN], in;
bool vis[mxN][mxN];


bool isok(int i, int j){
	return i>=0 && i<n && j>=0 && j<m && s[i][j]=='W' && !vis[i][j]; 
}

void dfs(int i, int j){
	vis[i][j] = 1;
	for(int k = 0; k < 8; k++){
		int ni = i + di[k], nj = j + dj[k];
		if(isok(ni, nj)){
			dfs(ni, nj);
		}
	}
	ans++;
}

int main()
{
	int t;
	cin >> t;
	getline(cin, in);
	getline(cin, in);
	for(int c = 0; c < t; c++){
		getline(cin, in); 
		int k = 0;
		while(1){
			if(in.length() == 0 || (in[0] != 'L' && in[0] !='W')){
				break;
			}
			s[k++] = in;
			getline(cin, in);
		}
		n = k, m = s[0].length();
		memset(vis, false, sizeof(vis));
		if(c != 0){
			cout << '\n';
		}
		while(1){
			stringstream ss(in);
			int u, v;
			ss >> u;
		    ss >> v;
			u--, v--;
			ans = 0;
			memset(vis, 0, sizeof(vis));
			dfs(u, v);
			cout << ans << '\n';	
			if(cin.eof()){
				break;
			}
			getline(cin, in);
			if(in.length() == 0){
				break;
			}
		}
	}	
	return 0;
}

