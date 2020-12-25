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


/* if  mod is not a prime number usr phi function; i.e. a^b^c mod m = a^(b^c mod phi(m)) mod m;
ll phi(ll n)
{
  ll cnt = 0;
  ll tmp= n;
  for(ll i = 2;  i*i <= tmp; i++){
    if(n%i){
      while(n%i == 0){
        n /= i;
      }
      cnt++;
    }
  }
  if(n != 1){
    cnt++;
  }
  return cnt;
}
*/

ll binpow(ll base, ll index, int mod)
{
  ll res = 1;
  while(index){
    if(index&1){
      res = (res*base)%mod;
    }
    base = (base*base)%mod;
    index >>= 1;
  }
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int tt;
  cin >> tt;
  ll a, b, c;
  while(tt--){
    cin >> a >> b >> c;
    cout << binpow(a, binpow(b, c, mod1-1), mod1) << '\n';
  }
  return 0;
}

