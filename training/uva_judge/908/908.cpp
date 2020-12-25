#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6;
int n, m, k;
int parent[mxN], ranks[mxN];

struct Edge{
    int src, dst, cost;
    Edge(int _src, int _dst, int _cost){
        src = _src;
        dst =_dst;
        cost = _cost;
    }
    bool operator<(Edge other){
        return cost < other.cost;
    }
};

void make_set(int v){
    parent[v] = v;
    ranks[v] = 0;
}

int find_set(int v){
    if(v == parent[v]) return v;
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
        if(ranks[a] == ranks[b]);{
            ranks[a]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    
    return 0;
}
