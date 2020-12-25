#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
int n, m;
string in, lines[mxN];
vector<int> adj[mxN], ts;
map<char, int> node_id;
map<int, char> node_name;
bool vis[mxN];

void dfs(int u){
    vis[u] = 1;
    for(int v : adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    ts.emplace_back(u);
}
int main()
{
    int id = 0, index = 0;
    void init();
    while(cin >> in){
        if(in == "#"){
            break;
        }
        lines[index] = in;
        for(int i = 0; i < (int)in.length(); i++){
            if(node_id.find(in[i]) == node_id.end()){
                node_id[in[i]] = id;
                node_name[id] = in[i];
                id++;
            }
        }
        index++;
    }

    n = id;
    for(int i = 1; i < index; i++){
        string prev_str = lines[i-1], curr_str = lines[i];
        for(int j = 0; j < (int)prev_str.length() && j < (int)curr_str.length(); j++){
            if(prev_str[j] != curr_str[j]){
                adj[node_id[prev_str[j]]].push_back(node_id[curr_str[j]]);
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }

    reverse(ts.begin(), ts.end());
    for(int a : ts){
        cout << node_name[a];
    }
    cout << endl;
    return 0;
}

