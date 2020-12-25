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


int P[500], W[500];
int dp[10001];

int solve(int n, int totalWt)
{

	dp[0] = 0;
	for(int i = 1; i <= totalWt; i++){
		dp[i] = -1;
		for(int j = 0; j < n; j++){
			if(i >= W[j] && dp[i - W[j]]!=-1 && (dp[i]==-1 || P[j]+dp[i-W[j]] <= dp[i])){
				dp[i] = P[j]+dp[i-W[j]]	;
			}
		}
	}
	return dp[totalWt];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int tt;
  cin >> tt;
  while(tt--){
  	int E, F, n;
  	cin >> E >> F >> n;
  	for(int i = 0; i < n; i++){
  		cin >> P[i] >> W[i];
  	}
  	cout << solve(n, F-E) << '\n';
  }
  return 0;
}