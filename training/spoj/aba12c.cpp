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

using namespace std;

int t, n, k;
int val[102];
int dp[101][101];

int solve(int n, int k)
{
  for(int i = 0; i <= n; i++){
    for(int j = 0; j <= k; j++){
      if(i == 0 or j == 0){
        dp[i][j] = 0;
      }
      if(i+1 <= j){
        dp[i][j] = min()
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  while(t--){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
      cin >> val[i];
    }
    cout << solve(n, k) << '\n';
  }
  return 0;
}

