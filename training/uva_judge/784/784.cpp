#include <bits/stdc++.h>
using namespace std;

const int mxN = 30, di[4]={1, 0, -1, 0}, dj[4]={0, 1, 0, -1};
int n, m, si, sj;
string s[mxN], in, br;

bool isok(int i, int j){
	return i>=0 && i<n && j>=0 && j<(int)s[i].length() && s[i][j] == ' ';
}

void dfs(int i, int j){
	s[i][j] = '#'; 
	for(int k = 0; k < 4; k++){
		int ni = i+di[k], nj = j+dj[k];
		if(isok(ni, nj)){
			dfs(ni, nj);
		}
	}
}

int main()
{	
	ofstream fout("out");
	int t;
	cin >> t;
	getline(cin, in); // read the newline character at the start
	for(int k = 0; k < t; k++){
		in.clear();
		getline(cin, in);  // read maze from here
		int i = 0;
		while(1){
			if(in[0] == '_'){ // break if hit the partition line
				br = in;
				break;
			}
			s[i] = in;
			for(int j = 0; j < (int)s[i].length(); j++){
				if(s[i][j] == '*'){
					si = i, sj = j; s[i][j] = '#';
				}
			}
			i++;
			getline(cin, in);
		}
		n = i
		dfs(si, sj);
		for(int j = 0; j < n; j++){
			cout << s[j] << '\n';
		}
		cout << br << '\n';
	}
	return 0;
}


