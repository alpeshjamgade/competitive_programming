#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
int n, m, s, t, d[mxN];
vector<array<int, 2>> adj[mxN];
bool vis[mxN];


void init(){
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < n; i++){
        adj[i].clear();
        d[i] = INT_MAX;
    }
}

void solve(){
    cin >> n >> m >> s >> t;
    init();
    for(int i = 0, u, v, w; i < m; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<array<int,2>,  vector<array<int, 2>>, greater<array<int, 2>>> pq;
    d[s] = 0;
    pq.push({0, s}); 
    while(pq.size()){
        array<int, 2> uu = pq.top();
        pq.pop();
        int u = uu[1];
        if(vis[u]) continue;
        vis[u] = 1;
        for(array<int, 2> vv : adj[u]){
            int v = vv[0], w = vv[1];
            if(d[v] > d[u]+w){
                d[v] = d[u]+w;
                pq.push({d[v], v});
            }
        }
    }
    if(d[t] == INT_MAX) cout << "unreachable\n";
    else cout << d[t] << '\n';
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test_case;
    cin >> test_case;
    for(int i = 1; i <= test_case; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
