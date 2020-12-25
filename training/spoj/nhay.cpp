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


vector<int> computeZ(string s)
{
  int l = s.length();
  vector<int> z(l);
  z[0] = 1;
  int left = 0, right = 0;
  for(int k = 1; k < l; k++){
    if(k > right){
      left = right = k;
      while(right < l && s[right] == s[right-left]){
        right++;
      }
      z[k] = right-left;
      right--;
    }
    else{
      int k1 = k - left;
      if(z[k1] < right-k+1){
        z[k] = z[k1];
      }
      else{
        left = k;
        while(right < l && s[right] == s[right-left]){
          right++;
        }
        z[k] = right-left;
        right--;
      }
    }
  }
  return z;
}

vector<int> z_search(string text, string pattern)
{

  string s = pattern + '$'+ text;
  vector<int> z = computeZ(s), res;
  for(int i = 0; i < z.size(); i++){
    if(z[i] == pattern.length()){
      res.emplace_back(i-pattern.length()-1);
    }
  }
  return res;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int x;
  string text, pattern;
  while(cin >> x){
    cin >> pattern >> text;
    auto res = z_search(text, pattern);
    for(int i = 0; i < res.size(); i++){
      cout << res[i] << '\n';
    }
    cout << '\n';
  }
  return 0;
}

