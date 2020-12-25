#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define fi first
#define se second
#define pi 3.1415926535
#define mod1 1000000007
#define mod2 1000000009
#define mp make_pair
#define no_of_digits(n) floor(log10(n)) + 1
#define lcm(a, b) (a/__gcd(a,b)*b)
#define sdebug(n) cout << "\n' n = " << n << " '\n";

using namespace std;

const int mxN = 2e5;
ll n, q;
ll arr[mxN+1];

void L()
{
  cin >> n >> q;
  for(int i = 0; i < n; i++){
    cin >> arr[i+1];
    arr[i+1] += arr[i];
  }
  int a, b;
  while(q--){
    cin >> a >> b;
    a--;
    cout << arr[b]-arr[a] << '\n';
  }
}

// my code starts here
void construct(vector<ll>&tree, vector<ll>&a, int st, int ed, int node)
{
  if(st == ed){
    tree[node] = a[st];
  }
  else{
    int md = (st+ed) >> 1;
    int ln = node << 1;
    int rn = ln + 1;
    construct(tree, a, st, md, ln);
    construct(tree, a, md+1, ed, rn);
    tree[node] = tree[ln]+tree[rn];
  }
}

void update_single(vector<ll> &tree, vector<ll> &a, int st, int ed, int idx, int val, int node)
{
  if(st == ed){
    tree[node] += val;
  }
  else{
    int md = st + (ed-st)/2;
    int ln = node >>1;
    int rn = ln + 1;
    if(st >= idx && idx <= ed){
      update_single(tree, a, st, md, idx, val, ln);
    }
    else{
      update_single(tree, a, md+1, ed, idx, val, rn);
    }
    tree[node] = tree[ln]+tree[rn];
  }
}

void update_range(vector<ll>&tree, vector<ll> &a, int st, int ed, int l, int r, int val, int node)
{
  if(st > ed || st > r || ed < l){
    return ;
  }
  if(st == ed){
    tree[node] += val;
    return;
  }
  int md = st + (ed-st)/2;
  int ln = node >> 1;
  int rn = ln +1;
  update_range(tree, a, st, md, l, r, val, ln);
  update_range(tree, a, md+1, ed, l, r, val, rn);
  tree[node] = tree[ln] + tree[rn];
}
ll query(vector<ll> &tree, vector<ll> &a, int st, int ed, int l, int r, int node)
{
  if(r < st || ed < l){
    return 0;
  }
  if(l <= st && ed <= r){
    return tree[node];
  }
  int md = st + (ed-st)/2;
  int ln = node << 1;
  int rn = ln + 1;
  ll p1 = query(tree, a, st, md, l, r, ln);
  ll p2 = query(tree, a, md+1, ed, l, r, rn);
  return p1+p2;
}

void update_rangeLP(vector<ll> &tree, vector<ll> &a, vector<ll> &lazy, int st, int ed, int l, int r, int val, int node)
{
  if(lazy[node] != 0){
    tree[node] += (ed-st+1)*lazy[node];
    if(st != ed){
      lazy[node*2] += lazy[node];
      lazy[node*2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if(st > ed || st > r || ed < l){
    return ;
  }
  if(st >= l || ed <= r){
    tree[node] += (ed-st+1)*val;
    if(st != ed){
      lazy[node*2] += val;
      lazy[node*2 +1] += val;
    }
    return;
  }
  int md = st+(ed-st)/2;
  update_rangeLP(tree, a, lazy, st, md, l, r, val, node*2);
  update_rangeLP(tree, a, lazy, md+1, ed, l, r, val, node*2+1);
  tree[node] = tree[node*2] + tree[node*2 +1 ];
}

int queryLP(vector<ll> &tree, vector<ll> &a, vector<ll> &lazy, int st, int ed, int l, int r, int node)
{
  if(st > ed || st > r || ed < l){
    return 0;
  }
  if(lazy[node] != 0){
    tree[node] += (ed-st+1)*lazy[node];
    if(st != ed){
      lazy[node*2] += lazy[node];
      lazy[node*2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if(st>=l && ed <= r){
    return tree[node];
  }
  int md = st + (ed-st)/2;
  int p1 = queryLP(tree, a, lazy, st, md, l, r, node*2);
  int p2 = queryLP(tree, a, lazy, md+1, ed, l, r, node*2+1);
  return p1+p2;
}


// my code ends here

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  /*
  int n, q, x, y;
  cin >> n >> q;

  vector<ll> a(n), tree(4*n), lazy(4*n);
  for(int i = 0;  i < n; i++){
    cin >> a[i];
  }

  construct(tree, a, 0, n-1, 1);
  while(q--){
    cin >> x >> y;
    cout << query(tree, a, 0, n-1, x-1, y-1, 1) << '\n';
  }
  */
  L();
  return 0;
}

