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

int n, s;
int a[2001], w[2001];
int dp[2001][2001];

int solve(int n, int s)
{
	if(n <= 0 || s <= 0){
		return 0;
	}
	if(dp[n][s] != -1){
		return dp[n][s];
	}
	if(w[n-1] <= s){
		dp[n][s] = max(a[n-1]+solve(n-1, s-w[n-1]), solve(n-1, s));
	}
	else{	
		dp[n][s] = solve(n-1, s);
	}
	return dp[n][s];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> s >> n;
  for(int i = 0; i < n; i++){
  	cin >> w[i] >> a[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(n, s);
  return 0;
}