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

const int mxN = 1e6;
ll dp[mxN+1];

ll  L(ll n){
	if(n <= 11){
		return n;
	}
	if(n <= mxN){
		if(dp[n] == 0){
			dp[n] = max(n, (L(n/2)+L(n/3)+L(n/4)));
			return dp[n];
		}
		return dp[n];
	}
	return max(n, (L(n/2)+L(n/3)+L(n/4)));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n;
  memset(dp, 0, sizeof(dp));
  while(cin >> n){
    cout << L(n) << '\n';
  }

  return 0;
}

