#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
int n, m;
int parent[mxN], ranks[mxN];

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
    while(cin >> n >> m && (n || m)){
        
        int src, dst, weight;
        int total_weight = 0;
        vector<Edge> edges, result;
        int cost = 0;
        // make disjoint sets for each of the vertex in the graph;
        for(int i = 0; i < n; i++){
            make_set(i);
        }

        // add edges;
        for(int i = 0; i < m; i++){
            cin >> src >> dst >> weight;
            total_weight += weight;
            //cout << src << ' ' << dst << ' ' << weight << '\n';
            edges.push_back(Edge(src, dst, weight));
        }

        // one can sort this edges or just store the edges in the priority queue with required operator..;
        sort(edges.begin(), edges.end());
        // now the unification process.
        // pick all the edges from first to last and if the ends of current edge belong to different set,
        // these sets are combined  and the edge is added to the result.
        for(Edge e : edges){
            if(find_set(e.src) != find_set(e.dst)){
                cost += e.weight;
                result.push_back(e);
                union_sets(e.src, e.dst);
            }
        }
        // After iterating through all the edges, all the vertices will belong to the same subtree.
        cout << total_weight-cost << '\n';
        // The answer is the total_weight of the graph minus the weight of the MST;
    }
    return 0;
}
