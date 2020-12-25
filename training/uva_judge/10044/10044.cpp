#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
int n, m, d[mxN];
string in;
map<string, int> node_id;
set<int> adj[mxN];
bool vis[mxN];
ofstream fout("out");

void BFS(int start){
    queue<int> qu;
    qu.push(start);
    d[start] = 0;
    vis[start] = 1;
    while(qu.size()){
        int u = qu.front();
        qu.pop();
        for(int v : adj[u]){
            if(!vis[v]){
                d[v] = d[u]+1;
                vis[v] = 1;
                qu.push(v);
            }
        }
    }
}

void trim(string &x){
    if(x[0] == ' '){ x.erase(0, 1); }
    if(x[x.length()-1] == ' '){ x.erase(x.length()-1, x.length()); }
}

void make_edges(vector<vector<string>> E){
    for(int k = 0; k < (int)E.size(); k++){
        for(int i = 0; i < (int)E[k].size(); i++){
            for(int j = 0; j < (int)E[k].size(); j++){
                if(i != j){
                    adj[node_id[E[k][i]]].insert(node_id[E[k][j]]);
                    adj[node_id[E[k][j]]].insert(node_id[E[k][i]]);
                }
            }
        }
    }
}

void init(){
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < n; i++){
        adj[i].clear();
        d[i] = INT_MAX;
    }
}

void solve(){
    int id = 0;
    int x, y;
    cin >> x >> y;
    cin.ignore();
    vector<vector<string>> E;
    node_id.clear(); // need to clear the node_id. Going to use it.
    for(int i = 0; i < x; i++){
        getline(cin, in, ':');
        cin.ignore(1000, '\n');
        //cout << in << '\n'; // lines excluding the Paper-Name has been read till this point;
        stringstream ss(in);
        string name, tmp;
        bool first_comma = true;
        vector<string> vs;
        while(ss.good()){
            getline(ss, tmp, ',');
            if(first_comma){
                name += tmp;
                name += ',';
                first_comma = 0;
                continue;
            }else{
                first_comma = 1;
                name += tmp;
                trim(name);
                //cout << "[" << name << "] "; //at this point all the names are extracted, now need to map them to numbers;
                if(node_id.find(name) == node_id.end()){
                    node_id[name] = id++; // names mapped to the numbers;
                    //cout << name << " is mapped to " << id-1 << '\n';
                }
                vs.push_back(name);
                name.clear();
            }
        }
        E.push_back(vs);
        //cout << '\n';
    }

    n = id;  // The number of mapping's made is nothing but the number of nodes in the graph;
    
    init();
    make_edges(E);
    /*
    for(int i = 0; i < n; i++){
        cout << i << ": ";
        for(int j : adj[i]){
            cout << j << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    */
    int start = node_id["Erdos, P."];
    //cout << start << '\n';
    BFS(start);
    /*
    for(int i = 0; i < n; i++){
        cout << i << " : " << d[i] << '\n';
    }
    cout << '\n';
    */
    for(int i = 0; i < y; i++){
        getline(cin, in);
        cout << in << ' ';
        if(d[node_id[in]] == INT_MAX){
            cout << "infinity\n";
        }else{
            cout << d[node_id[in]] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt;
    cin >> tt;
    int __case = 1;
    while(tt--){
        cout << "Scenario " << __case++ << '\n';
        solve();
    }
    return 0;
}
