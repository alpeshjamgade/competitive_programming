#include <bits/stdc++.h>
using namespace std;


const int mxN = 1e3, di[4]={1, 0, -1, 0}, dj[4]={0, 1, 0, -1};
int n, m, cnt, ans=0;
string s[mxN];
bool vis[mxN];

bool isok(int i, int j){
    return i>=0&&i<m&&j>=0&&j<n&&s[i][j]=='.';
}

int dfs(int i, int j){
    s[i][j] = '#';
    int res = 0;
    for(int k = 0; k <  4; k++){
        int ni = di[k]+i, nj = dj[k]+j;
        if(isok(ni, nj)){
            res = max(1+dfs(ni, nj), res);
        }
    }
    return res;
}

void init(){
    for(int i = 0; i < m; i++){
        s[i].clear();
    }
    ans = 0;
    memset(vis, false, sizeof(vis));
}

int solve(){
    cin >> n >> m;
    init();
    for(int i = 0; i < m; i++){
        cin >> s[i];
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j] == '.'){
                ans = max(dfs(i, j), ans);
            }
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    while(tt--){
        ans = 0;
        int res = solve();
        printf("Maximum rope length is %d.\n", res);
        init();
    }
    return 0;
}
