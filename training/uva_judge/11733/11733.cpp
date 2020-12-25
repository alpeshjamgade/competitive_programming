#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
int n, m, a;
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

void union_sets(int u, int v){
	u = find_set(u);
	v = find_set(v);
	if(ranks[u] < ranks[v]){
		swap(u, v);
	}
	parent[v] = u;
	if(ranks[u] == ranks[v]){
		ranks[u]++;
	}

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ofstream fout("out");

    int test_case;
    cin >> test_case;
    for(int t = 1; t <= test_case; t++){
    	cin >> n >> m >> a;
    	int src, dst, cost, ans1 = 0, ans2 = 0;
    	vector<Edge> edges, edges2;
    	for(int i = 0; i < m; i++){
    		cin >> src >> dst >> cost;
    		edges.emplace_back(Edge(src, dst, cost));
    	}
    	for(int i = 0; i < n; i++){
    		make_set(i);
    	}
    	sort(edges.begin(), edges.end());
    	for(Edge e : edges){
    		if(find_set(e.src) != find_set(e.dst)){
    			ans1 += e.cost;
    			union_sets(e.src, e.dst);
    		}
    	}
    	cout << ans1 << '\n';
    }
    return 0;
}
