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

const int mxN = 1e6, mxM = 100;
int n, x;
int c[mxM];
ll dp[mxN+1];
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  cin >> n >>  x;
  for(int i = 0; i < n; i++){
    cin >> c[i];
  }

  for(int i = 1; i <= x; i++){
    dp[i] = 1e9;
    for(int j = 0; j < n; j++){
      if(c[j] <=i){
        dp[i]=min(dp[i], dp[i-c[j]]+1);
      }
    }
  }
  if(dp[x] >= 1e9)
    cout << -1;
  else
  cout << dp[x];
  return 0;
}

