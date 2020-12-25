#include <bits/stdc++.h>
using namespace std;
#define debug

const int mxN = 60, di[4]={1, 0, -1, 0}, dj[4]={0, 1, 0, -1};
int n, m, cnt;
string s[mxN];
vector<pair<char, int>> ans;
bool vis[mxN][mxN];

bool isok(int i, int j){
	return i>=0 && i<n && j>=0 && j<m && !vis[i][j];
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

void init(){
	memset(vis, false, sizeof(vis));
	ans.clear();
}

int main()
{
	ofstream fout("out");
	int t;
	cin >> t;
	for(int k = 1; k <=t; k++){
		cin >> n >> m;
		init();
		for(int i = 0; i < n; i++){
			cin >> s[i];
		}
		map<char, int> mp;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(isok(i, j)){
					dfs(i, j);
					mp[s[i][j]]++;
				}
			}
		}
		for(auto a : mp){
			ans.push_back(make_pair(a.first, a.second));
		}
		sort(ans.begin(), ans.end(), cmp);
		cout << "World #" << k << '\n';
		for(auto a : ans){
			cout << a.first << ": " << a.second << '\n';
		}
	}
	return 0;
}

