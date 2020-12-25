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
int n, m, k, a[mxN], b[mxN];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < m; i++){
    cin >> b[i];
  }

  sort(a, a+n);
  sort(b, b+m);
  int ans = 0;
  for(int i = 0, j = 0, i < n;  ++i){
    while(j < m && b[j] < a[i]-k){
      ++j;
    }
    if(j < m && b[j]<=a[i]+k){
      ++ans, ++j;
    }
  }
  cout << ans;
  return 0;
}

