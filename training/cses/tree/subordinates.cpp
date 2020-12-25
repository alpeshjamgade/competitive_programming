#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3;
int n, s[mxN];
vector<int> adj[mxN];

void dfs(int u, int pu = -1){
    s[u] = 1;
    for(int v : adj[u]){
        dfs(v, u);
        s[v] += s[u];

    }
}

int main()
{
    cin >> n;
    for(int i = 1, u; i < n; i++){
        cin >> u;
        adj[u].emplace_back(i);
    }
    dfs(0);
    for(int i = 0; i < n; i++){
        cout << s[mxN] << ' ';
    }
    return 0;
}

