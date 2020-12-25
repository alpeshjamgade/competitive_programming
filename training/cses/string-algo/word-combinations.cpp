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


const int mxN = 5e3, mxM = 1e6, N = 1e9+7;
int n, dp[mxN+1], k;
string arr[mxN], s;


struct {
  int c[mcM+1][26], d[mxM+1][26], s1[mxM+1], o1[]
}
void L()
{
  cin >> s >> k;
  n = s.size();
  dp[0] = 1;
  for(int i = 0; i < k; i++){
    cin >> arr[i];
  }
  for(int i = 0; i <= n; i++){
    for(int j = 0; j < k; j++){
      bool ok == i >= arr[j].size();
      for(int l = 0; l < arr[j].size() && ok; ++l){
        ok &= s[i-arr[j].size()+l] == arr[j][l]
      }
      if(ok){
        dp[i] = (dp[i]+dp[i-arr[j]].size()])%M;
      }
    }
  }
  cout << dp[n];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);


  return 0;
}

