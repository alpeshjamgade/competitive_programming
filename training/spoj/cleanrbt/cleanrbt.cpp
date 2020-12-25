#include <bits/stdc++.h>
using namespace std;
// Matsuo hayato
// daniel portero
const int mxN = 20, di[4]={1, 0, -1, 0}, dj[4]={0, 1, 0, -1};
int n, m, si, sj, d[mxN][mxN];
string s[mxN];
vector<array<int,2>> dirt;
bool vis[mxN][mxN];

bool isok(int i, int j){
    return i >= 0 && i < m && j >= 0 && j < n && s[i][j] != 'x';
}

void init(){
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            d[i][j] = INT_MAX;
        }
        s[i].clear();
    }
    dirt.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n >> m && (n && m)){
        init();
        for(int i = 0; i < m; i++){
            cin >> s[i];
            for(int j = 0; j < n; j++){
                if(s[i][j] == 'o'){
                    si = i, sj = j;
                }
                if(s[i][j] == '*'){
                    dirt.push_back({i, j});
                }
                if(s[i][j] == 'x'){
                    vis[i][j] = 1;
                }
            }
        }

        queue<array<int, 2>> qu;
        qu.push({si, sj});
        d[si][sj] = 0;
        vis[si][sj] = 1;
        while(qu.size()){
            array<int, 2> u = qu.front();
            qu.pop();
            for(int k = 0; k < 4; k++){
                int ni = u[0]+di[k], nj = u[1]+dj[k];
                if(!isok(ni, nj)) continue;
                d[ni][nj] = min(d[ni][nj], d[u[0]][u[1]]+1);
                qu.push({ni,nj});
                vis[ni][nj] = 1;
                s[ni][nj] = 'x';
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << d[i][j] << ' ';
            }
            cout << '\n';
        }
        int answer = 0;
        bool flag = 1;
        for(int i = 1; i < (int)dirt.size(); i++){
            array<int,2> u = dirt[i];
            array<int,2> v = dirt[i-1];
            if(!vis[u[0]][u[1]] || !vis[v[0]][v[1]]){
                flag = 0; break;
            }
            answer += abs(d[u[0]][u[1]] - d[v[0]][v[1]]);
        }
        if(flag) cout << answer << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}
