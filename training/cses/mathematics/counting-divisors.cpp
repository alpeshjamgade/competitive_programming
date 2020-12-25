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

int div1(int n)
{
  int  res = 1;
  int tmp = n;
  for(int i = 2; i*i <= n; i++){
    if(tmp % i == 0){
      int t= 0;
      while(tmp%i == 0){
        t++;
        tmp /= i;
      }
      res *= (pow(i, t)+1);
    }
  }
  return res;
}


int div2(int n)
{
  int res = 1;

  for(int i = 2; i*i <= n; i++){
    if(n%i == 0){
      if(n/i != i){
        res++;
      }
      res++;
    }
  }
  if(n != 1){
    res++;
  }
  return res;
}

const int mxA = 1e6;
int lpf[mxA+1];
vector<int> pfs;
void tmw()
{
  for(int i = 2; i <= mxA; i++){
    if(!lpf[i]){
      pfs.push_back(i);
      lpf[i] = i;
    }
    for(int j = 0; j < pfs.size() && pfs[j]<=i*pfs[j]<=mxA;++j){
      lpf[i*pfs[j]] = pfs[j];
    }
  }
  int n;
  cin >> n;
  while(n--){
    map<int, int> m;
    int x;
    cin >> x;
    while(x>1){
      mp[lps[x]]++;
      x/=lpf[x];
    }
    int ans = 1;
    for(auto p: m){
      ans *= (p.second+1);
    }
    cout << ans << '\n';
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ll n, x;
  cin >> n;
  while(n--){
    cin >> x;
    cout << div2(x) << '\n';
  }
  return 0;
}

