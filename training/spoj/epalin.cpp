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



int computeLPS(string pattern)
{
  int l = pattern.length();
  vector<int> lps(l);
  int j = 0;
  for(int i = 1; i < l;){
    if(pattern[i] == pattern[j]){
      lps[i] = j+1;
      i++; j++;
    }
    else{
      if(j != 0){
        j = lps[j-1];
      }
      else{
        lps[i] = 0;
        i++;
      }
    }
  }
  return lps[l-1];
}



int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  while(cin >> s){

    string rs =s;
    reverse(rs.begin(), rs.end());
    string x = rs+s;
    int l = s.length() - computeLPS(x);
    cout << s;
    for(int i = l-1; i >= 0; i--){
      cout << s[i];
    }
    cout << '\n';
  }
  return 0;
}

