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


int o2[1000], n2[1000], wt[1000];
int dp[1001][22][80];
int O, N, n;

int solve(int n, int O, int N)
{
	if(O == 0 && N == 0)return 0;
	if(n == 0) return 100000;
	if(dp[n][O][N] != -1) return dp[n][O][N];
	dp[n][O][N] = min(solve(n-1, O, N), solve(n-1, O - min(O, o2[n-1]), N - min(N, n2[n-1])) + wt[n-1]);
	return dp[n][O][N];
}

void solve2(int n, int O, int N)
{
	for(int i = 1; i<=n; i++){
		for(int j = 1; j <= O; j++){
			for(int k = 1; k <= N; k++){
				if(wt[i-1] <= j && wt[])
			}
		}
	}
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int tt;
  cin >> tt;
  while(tt--){
  	cin >> O >> N >> n;
  	for(int i = 0; i < n; i++){
  		cin >> o2[i] >> n2[i] >> wt[i];
  	}

  	for(int i = 0; i <= n; i++){
  		for(int j = 0; j <= O; j++){
  			for(int k = 0; k <= N; k++){
  				dp[i][j][k] = -1;
  			}
  		}
  	}
  	cout << solve(n, O, N) << '\n';
  }
  return 0;
}