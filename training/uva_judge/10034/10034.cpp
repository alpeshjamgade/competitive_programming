#include <bits/stdc++.h>
using namespace std;

vector<int> parent, ranks;

void make_set(int v){
    parent[v] = v;
    ranks[v] = 0;

}

int find_set(int v){
    if(v == parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(ranks[a] < ranks[b]){
            swap(a, b);
        }
        parent[b] = a;
        if(ranks[a] == ranks[b]){
            ranks[a]++;
        }
    }
}

struct Edge{
    int src, dst, weight;
    bool operator<(Edge const& other){
        return weight < other.weight;
    }
    Edge(int _src, int _dst, int _weight){
        src = _src;
        dst = _dst;
        weight = _weight;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    int src, dst, weight;
    while(cin >> n >> m && (n || m)){
        vector<Edge> edges, result;
        int cost = 0;
        parent.resize(n);
        ranks.resize(n);
        for(int i = 0; i < n; i++){
            make_set(i);
        }
        for(int i = 0; i < m; i++){
            cin >> src >> dst >> weight;
            cout << src << ' ' << dst << ' ' << weight << '\n';
            edges.push_back(Edge(src, dst, weight));
        }

        sort(edges.begin(), edges.end());
        for(int i = 0; i < m; i++){
           // cout << edges[i].src << ' ' <<  edges[i].dst <<' '<< edges[i].weight << '\n';
        }
        for(Edge e : edges){
            if(find_set(e.src) != find_set(e.dst)){
                cost += e.weight;
                result.push_back(e);
                union_sets(e.src, e.dst);
            }
        }
        cout << cost << '\n';
    }
    return 0;
}
