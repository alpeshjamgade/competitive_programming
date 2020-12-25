#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define debug

const int mxN = 60, di[4]={1, 0, -1, 0}, dj[4]={0, 1, 0, -1};
int n, m, cnt;
string s[mxN];
vector<pair<char, int>> ans;
bool vis[mxN][mxN];

bool isok(int i, int j){
	return i>=0 && i<n && j>=0 && j<m && s[i][j] != '.' && !vis[i][j];
}

bool cmp(pair<char, int> a, pair<char, int> b){
	if(a.second == b.second){
		return a.first < b.first;
	}
	return a.second >= b.second;
}

void dfs(int i, int j){
	vis[i][j] = 1;
	for(int k = 0; k < 4; k++){
		int ni = i+di[k], nj = j+dj[k];
		if(isok(ni, nj) && s[i][j] == s[ni][nj]){
			dfs(ni, nj);
		}
	}
	cnt++;
}

int main()
{
	ofstream fout("out");
	int t = 1;
	while(cin >> n >> m && (n||m)){
		for(int i = 0; i < n; i++){
			cin >> s[i];
		}
		memset(vis, false, sizeof(vis));
		ans.clear();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(isok(i, j)){
					cnt = 0;
					dfs(i, j);
					ans.push_back(mp(s[i][j], cnt));
				}
			}
		}
		sort(ans.begin(), ans.end(), cmp);
		cout << "Problem " << t++ << ":\n";
		for(auto a : ans){
			cout << a.first << ' ' << a.second << '\n';
		}
	}
	return 0;
}

