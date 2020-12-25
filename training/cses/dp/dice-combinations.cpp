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

const int mxN = 1e6;
ll dp[mxN];

ll L()
{
  ll n; cin >> n;
  dp[0] = 1;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= min(i, 6); j++){
      dp[i] = (dp[i] + dp[i-j])%mod1;
    }
  }
  return dp[n];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cout << L() << '\n';
  return 0;
}

