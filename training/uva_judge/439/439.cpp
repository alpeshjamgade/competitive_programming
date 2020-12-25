#include <bits/stdc++.h>
using namespace std;

const int mxN = 9, di[8]={2, 2, 1, -1, -2, -2, -1, 1}, dj[8]={-1, 1, 2, 2, 1, -1, -2, -2};
int si, sj, ti, tj, d[mxN][mxN];
bool vis[mxN][mxN];
string s;

bool isok(int i, int j){
	return i>=1 && i<=8&& j >=1 && j<= 8 && !vis[i][j];
}

void init(){
	memset(d, 0, sizeof(d));
	memset(vis, 0, sizeof(vis));
}

void set_values(string s){
	si = (int)(s[0]-'a')+1;
	sj = (int)(s[1]-'0');
	ti = (int)(s[3]-'a')+1;
	tj = (int)(s[4]-'0');
	//cout << si << sj << ' ' << ti << tj << '\n';
}

int main()
{
	while(getline(cin, s)){
		init();
		set_values(s);
		queue<array<int, 2>> qu;
		qu.push({si, sj});
		vis[si][sj] = 1;
		d[si][sj] = 0;
		while(qu.size()){
			array<int, 2> u = qu.front();
			qu.pop();
			for(int k = 0; k < 8; k++){
				int ni = di[k]+u[0], nj= dj[k]+u[1];
				if(isok(ni, nj)){
					qu.push({ni, nj});
					vis[ni][nj] = 1;
					d[ni][nj] = d[u[0]][u[1]]+1;
				}
			}
		}
		cout << "To get from " << s[0] << s[1] <<" to " << s[3] << s[4] << " takes " << d[ti][tj] << " knight moves.\n";
	}
	return 0;
}





