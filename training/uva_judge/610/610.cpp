#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e3;
int n, m, timer, tin[mxN], low[mxN], c[mxN];
vector<int> adj[mxN];
vector<array<int, 2>> ans;

void dfs(int u, int pu=-1){
    c[u] = 0;
    tin[u] = low[u] = timer++;
    int children = 0;
    for(int v : adj[u]){
        if(c[v] == 0){
            // a back-edge;
            ans.push_back({u+1, v+1});
            low[u] = min(low[u], tin[v]);
        }
        else if(c[v] == -1){
            // a tree-edge;
            ans.push_back({u+1, v+1});
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            children++;
            if(low[v] > tin[u]){
                // a bridge;
                ans.push_back({v+1, u+1});
            }
        }
    }
    c[u] = 1;
}

void init(){
    timer = 0;
    memset(c, -1, sizeof(c));
    memset(tin, -1, sizeof(tin));
    memset(low, -1, sizeof(low));
    ans.clear();
    for(int i = 0; i < n; i++){
        adj[i].clear();
    }
}

int main()
{
    ofstream fout("out");
    int __case = 1;
    while(scanf("%d %d", &n, &m) &&(n&&m)){
        init();
        for(int i = 0, u, v; i < m; i++){
            cin >> u >> v, u--, v--;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        for(int i = 0; i < n; i++){
            if(c[i] == -1){
                dfs(i);
            }
        }
        cout << __case++ << "\n\n";
        for(array<int, 2> a : ans){
            cout << a[0] << ' ' << a[1] << '\n';
        }
        cout << "#\n";
    } 
    return 0;
}
