#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e3, LOGN = 22;
int n, p1[mxN], p2[mxN][mxN], h[mxN];
vector<int> adj[mxN];

void dfs1(int u, int pu = -1, int hu = -1){
    p1[u] = pu;
    h[u] = hu+1;
    for(int v : adj[u]){
        if(v == pu) continue;
        dfs1(v, u, h[u]);
   }
}


void dfs2(int u, int pu = -1, int hu = -1){
    h[u] = hu+1;
    p2[u][0] = hu+1;
    for(int i = 1; i < LOGN; i++){
        p2[u][i] = p2[p2[u][i-1]][i-1];
    }
    for(int v : adj[u]){
        if(v == pu) continue;
        dfs2(v, u);
    }
}

int find_lca_fast(int u, int v){
    while(u^v){
        int d = abs(h[u]-h[v]);
        int tmp = 1;
        int uu = (h[u] > h[v])?u:v;
        while(d){
            if(d&1){
                uu = p2[uu][tmp];
            }
            tmp <<= 1;
            d >>= 1;
        }
        (h[u]>h[v])?(u = uu):(v = uu);
    }
    return u;
}

int find_lca_slow(int u, int v){
    while(u^v){
        if(h[u] > h[v]){
            u = p1[u];
        }else{
            v = p1[v];
        }
    }
    return u;
}

int main()
{
    cin >> n;
    for(int i = 0, u, v; i < n-1; i++){
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs1(0);
    dfs2(0);
    return 0;
}


