#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6;
int n, t, m, k;
int parent[mxN], ranks[mxN];

struct Edge{
    int src, dst, cost;
    
    Edge(int _src, int _dst, int _cost){
        src = _src;
        dst = _dst;
        cost = _cost;
    }

    bool operator<(Edge const &other){
        return cost < other.cost;
    }
};

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("out");
    bool first = 1;

    while(cin >> n){
        int src, dst, cost;
        vector<Edge> new_edges;
        int ans1 = 0, ans2 = 0;
        for(int i = 0; i < n-1; i++){
            cin >> src >> dst >> cost;
            //chosen_edges.emplace_back(Edge(src, dst, cost));
            ans1 += cost;
        }
        cin >> k;
        for(int i = 0; i < k; i++){
            cin >> src >> dst >> cost;
            new_edges.push_back(Edge(src, dst, cost));
        }
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> src >> dst >> cost;
            new_edges.emplace_back(Edge(src, dst, cost));
        }

        for(int i = 0; i < (int)new_edges.size(); i++){
            make_set(i);
        }

        sort(new_edges.begin(), new_edges.end());
        for(Edge e : new_edges){
            if(find_set(e.src) != find_set(e.dst)){
                ans2 += e.cost;
                union_sets(e.src, e.dst);
            }
        }
        if(!first){
            cout << '\n';
        }else{
            first = 0;
        }
        cout << ans1 << '\n';
        cout << ans2 << '\n';
    }
    return 0;
}

