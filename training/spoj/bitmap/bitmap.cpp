nclude <bits/stdc++.h>
using namespace std;

const int mxN = 500, di[4]={1, 0, -1, 0}, dj[4]={0, 1, 0, -1};
int n, m, d[mxN][mxN];
string s[mxN];
vector<int> adj[mxN];
bool vis[mxN][mxN];

void init(){
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            d[i][j] = INT_MAX;
        }
    }
}

bool isok(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m;
}
void solve(){
    cin >> n >> m;
    init();
    vector<array<int, 2>> p;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(int j = 0; j < m; j++){
            if(s[i][j] == '1'){
                p.push_back({i, j});
            }
        }
    }
    queue<array<int,2>> q;
    for(auto a : p){
        q.push(a);
        d[a[0]][a[1]] = 0;
    }
    while(!q.empty()){
        array<int, 2> uu = q.front(); q.pop();
        if(vis[uu[0]][uu[1]]) continue;
        vis[uu[0]][uu[1]];
        for(int k = 0; k < 4; k++){
            int ni = di[k]+uu[0], nj = dj[k]+uu[1];
            if(isok(ni, nj) && d[ni][nj] > d[uu[0]][uu[1]]+1){
                d[ni][nj] = d[uu[0]][uu[1]]+1;
                q.push({ni, nj});
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}
