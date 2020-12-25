#include <bits/stdc++.h>
using namespace std;

const int mxN = 50, di[4]={1, 0, -1, 0}, dj[4]={0, 1, 0, -1};
int n, m, cnt;
string s[mxN];
vector<int> ans;


bool isok(int i, int j){
	return i>=0 && i<m && j>=0 && j<n && s[i][j] != '.';
}

void dfs2(int i, int j){
	s[i][j] = '*';
	for(int k = 0; k < 4; k++){
		int ni = i+di[k], nj = j+dj[k];
		if(isok(ni, nj) && s[ni][nj] == 'X'){
			dfs2(ni, nj);
		}
	}
}

void dfs1(int i, int j){
	if(s[i][j] == 'X'){
		cnt++;
		dfs2(i, j);
	}
	if(s[i][j] == '*'){
			s[i][j] = '.';
	}
	for(int k = 0; k < 4; k++){
		int ni = i+di[k], nj = j+dj[k];
		if(isok(ni, nj)){
			dfs1(ni, nj);
		}
	}
}

int main()
{
	ofstream fout("out");
	int t = 1;
	while(cin >> n >> m && (n||m)){
		for(int i = 0; i < m; i++){
			cin >> s[i];
		}
		ans.clear();
		cnt = 0;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(isok(i, j)){
					cnt = 0;
					dfs1(i, j);
					ans.push_back(cnt);
				}
			}
		}

		sort(ans.begin(), ans.end());
		cout << "Throw " << t++ << '\n';
		for(int i = 0; i < (int)ans.size(); i++){
			cout << ans[i];
			if(i != (int)ans.size()-1){
				cout << ' ';
			}	
		}
		cout << "\n\n";
	}	
	return 0;
}

