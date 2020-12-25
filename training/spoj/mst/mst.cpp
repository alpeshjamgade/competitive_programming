#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mxN = 1e4+1;
ll n, m;
ll parent[mxN], ranks[mxN];

struct Edge{
	ll src, dst, weight;
	Edge(ll _src, ll _dst, ll _weight){
		src = _src;
		dst = _dst;
		weight = _weight;
	}

	bool operator<(Edge const &other){
		return weight < other.weight;
	}
};

void make_set(ll v){
	parent[v] = v;
	ranks[v] = v;
}

ll find_set(ll v){
	if(v == parent[v]){
		return v;
	}
	return parent[v] = find_set(parent[v]);
}

void union_sets(ll a, ll b){
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

    cin >> n >> m;
    for(ll i = 0; i < n; i++){
    	make_set(i);
    }
    vector<Edge> edges;
    for(ll i = 0, src, dst, weight; i < m; i++){
    	cin >> src >> dst >> weight;
    	edges.emplace_back(Edge(src, dst, weight));
    }

    sort(edges.begin(), edges.end());
    ll ans = 0;
    for(Edge e : edges){
    	if(find_set(e.src) != find_set(e.dst)){
    		ans += (ll)e.weight;
    		union_sets(e.src, e.dst);
    	}
    }
    cout << ans << '\n';
    return 0;
}
