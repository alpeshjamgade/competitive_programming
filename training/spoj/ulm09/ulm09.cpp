#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5+1;
int n, m;
int parent[mxN], ranks[mxN];

struct Edge{
	int src, dst, weight;
	Edge(int _src, int _dst, int _weight){
		src = _src;
		dst = _dst;
		weight = _weight;
	}

	bool operator<(Edge const &other){
		return weight < other.weight;
	}
};

void make_set(int v){
	parent[v] = v;
	ranks[v] = v;
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
	if(ranks[a] < ranks[b]){
		swap(a, b);
	}
	parent[b] = a;
	if(ranks[a] == ranks[b]){
		ranks[a]++;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> n >> m && (n||m)){
    	for(int i = 0; i < n; i++){
    		make_set(i);
    	}
    	int src, dst, weight, total_weight = 0;
    	vector<Edge> edges;
    	for(int i = 0; i < m; i++){
    		cin >> src >> dst >> weight;
    		total_weight += weight;
    		edges.emplace_back(Edge(src, dst, weight));
    	}

    	sort(edges.begin(), edges.end());
    	int ans = 0;
    	for(Edge e : edges){
    		if(find_set(e.src) != find_set(e.dst)){
    			ans += e.weight;
    			union_sets(e.src, e.dst);
    		}
    	}
    	cout << total_weight - ans << '\n';
    }    
    return 0;
}
