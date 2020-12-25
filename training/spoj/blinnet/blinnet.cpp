#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN = 1e4+1;
int n, m;
string city;
ll parent[mxN], ranks[mxN];

struct Edge{
	int src, dst, cost;
	bool operator<(Edge const &other){
		return cost < other.cost;
	}

	Edge(int _src, int _dst, int _cost){
		src = _src;
		dst = _dst;
		cost = _cost;
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

    int test_cases;
    cin >> test_cases;
    while(test_cases--){
    	memset(parent, 0, sizeof(parent));
    	memset(ranks, 0, sizeof(ranks));
    	cin >> n;
    	vector<Edge> edges;
    	int id = 1;
    	for(int j = 0; j < n; j++){
	    	int src, dst, cost;
	    	src = id;
	    	cin >> city;
	    	cin >> m;
	    	for(int i = 0; i < m; i++){
	    		cin >> dst >> cost;
	    		edges.emplace_back(Edge(src, dst, cost));
	    	}
	    	id++;
	    }

	    for(int i = 0; i < n; i++){
	    	make_set(i);
	    }
	    ll ans = 0;
	    sort(edges.begin(), edges.end());
	    for(Edge e : edges){
	    	if(find_set(e.src) != find_set(e.dst)){
	    		ans += (ll)e.cost;
	    		union_sets(e.src, e.dst);
	    	}
	    }
	    cout << ans << '\n';
	}
    return 0;
}
