#include <bits/stdc++.h>
using namespace std;

const int mxN = 32, di[4]={1, 0, -1, 0}, dj[4]={0, 1, 0, -1};
int n, m;
string s[mxN], in, br;
char contour;

bool isok(int i, int j){
	return i>=0 && i<n && j>=0 && j<(int)s[i].length() && s[i][j] == ' ';
}

void dfs(int i, int j, char c){
	s[i][j] = c;
	for(int k = 0; k < 4; k++){
		int ni = i+di[k], nj = j+dj[k];
		if(s[ni][nj] != c && isok(ni, nj)){ 
			dfs(ni, nj, c);
		}
	}
}

int main()
{
	ofstream fout("out");
	while(getline(cin, in)){
		int i = 0;
		do{
			if(in[0] == '_'){
				br = in;
				break;
			}
			s[i] = in;

			// lazy way to find contour,
			if(i == 0){
				for(int j = 1; j < (int)in.length(); j++){
					if(in[j]!=' ' && in[j]!='_' && in[j]==in[j-1]){
						contour = in[j];
						break;
					}
				}
			}
			// ends here
			i++;
		}while(getline(cin, in));
		n = i;

		// now look for marker and apply dfs from that point.
		for(int i = 0; i < n; i++){
			for(int j = 0; j < (int)s[i].length(); j++){
				if(s[i][j] != contour && s[i][j] != ' ' && s[i][j] != '\t'){
					dfs(i, j, s[i][j]);
				}
			}
		}

		// finally print the grid.
		for(int i = 0; i < n; i++){
			cout << s[i] << '\n';
		}

		// dont forget the seperation line -> "_______"
		cout << br << '\n';
	}	
	return 0;
}


