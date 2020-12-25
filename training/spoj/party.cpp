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

int t[101][501];
int solve2(vector<int> cost, vector<int> fun, int n, int budget)
{
	if(n <= 0 || budget <= 0){
		return 0;
	}
	if(t[n][budget] != -1){
		return t[n][budget];
	}
	if(cost[n-1] <= budget){
		t[n][budget] = max(fun[n-1]+solve2(cost, fun, n-1, budget-cost[n-1]), solve2(cost, fun, n-1, budget));
		return t[n][budget];
	}
	else{
		t[n][budget] = solve2(cost, fun, n-1, budget);
		return t[n][budget];
	}
}

void solve(int budget, int n, vector<int> cost, vector<int> fun)
{
	vector<vector<int>> dp(n+1, vector<int>(budget+1, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= budget; j++){
			if(j < cost[i-1]){
				dp[i][j] = dp[i-1][j];
			}
			else{
				dp[i][j] = max(dp[i-1][j], fun[i-1]+dp[i-1][j-cost[i-1]]);
			}
		}
	}

	// for(int i = 0; i <=n; i++)
	// 	for(int j = 0; j <= budget; j++)
	// 		cout << dp[i][j] << "  ";
	// 	cout << '\n';

	int maxFun = dp[n][budget];
	int minCost = 0;
	for(int i = 0; i <= budget; i++){
		if(dp[n][i] == maxFun){
			minCost = i;
			break;
		}
	}

	cout << minCost <<  " " << maxFun; 
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int budget, n;
  cin >> budget >> n;
  while(1){
  	if(!budget && !n){
  		break;
  	}
  	vector<int> cost(n), fun(n);
  	for(int i = 0; i < n; i++){
  		cin >> cost[i] >>  fun[i];
  	}


  	memset(t, -1, sizeof(t));
  	//solve(budget, n, cost, fun);
  	int maxFun = solve2(cost, fun, n, budget);
  	int minCost = 0;
  	for(int i = 0; i <= budget; i++){
  		if(t[n][i] == maxFun){
  			minCost = i;
  			break;
  		}
  	}
  	cout << minCost << " " << maxFun;
  	// for(int i = 0; i <= n; i++){
  	// 	for(int j = 0; j <= budget; j++){
  	// 		cout << t[i][j] << "  ";
  	// 	}
  	// 	cout << "\n\n";
  	// }
  	cout << '\n';
  	cin >> budget >> n;
  }
  
  return 0;
}