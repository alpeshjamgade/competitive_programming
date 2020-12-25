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

int n, k;
int b[1000];
int dp[1001][1001];
int solve2(int i, int w)
{
	if(i >= n){
		return w;
	}
	if(dp[i][w] != -1){
		return dp[i][w];
	}
	if(b[i]+w <= k){
		dp[i][w] = max(solve2(i+2, w+b[i]), solve2(i+1, w));
	}
	else{
		dp[i][w] = solve2(i+1, w);
	}
	return dp[i][w];
}


int solve(int n, int k)
{
	if(n < 0){
		return 0;
	}
	if(dp[n][k] != -1){
		return dp[n][k];
	}
	if(b[n-1] <= k){
		dp[n][k] = max(b[n-1] + solve(n-2, k-b[n-1]), solve(n-1, k));
	}
	else{
		dp[n][k] = solve(n-1, k);
	}
	return dp[n][k];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int tt;
  cin >> tt;
  int c = 1;
  while(tt--){
  	cin >> n >> k;
  	for(int i = 0; i < n; i++){
  		cin >> b[i];
  	}
  	memset(dp, -1, sizeof(dp));
  	cout << "Scenario #" << c << ": ";
  	//cout << solve(n, k, b) << '\n';
  	cout << solve(n, k) << '\n';
  	c++;
  }
  return 0;
}