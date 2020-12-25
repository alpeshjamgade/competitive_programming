#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5+1;
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

    int test_cases;
    while(test_cases--){
    	cin >> n >> m;

    	for(int i = 0, x; i < n; i++){
    		cin >> x;
    		
    	}
    }    
    return 0;
}
