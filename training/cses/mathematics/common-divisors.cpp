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

const int mxA = 1e6;
int c[mxA+1];
 
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, x;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x;
    ++c[x];
  }

  for(int i = mxA; i > 0; i--){
    int d = 0;
    for(int j=i; j <= mxA; j+=i){
      d += c[j];
    }
    if(d>1){
      cout << i;
      break;
    }
  }
  return 0;
}

