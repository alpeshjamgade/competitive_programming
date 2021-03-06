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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ll n;
  cin >> n;

  while(1){
    cout << n << " ";
    if(n == 1){
      break;
    }
    if(n&1){
      n = n*3+1;
    }
    else{
      n /= 2;
    }
  }
  return 0;
}

