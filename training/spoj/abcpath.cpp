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

int n,, m;
string s[50];


void dfs(int i, int j, vector<int> &cnt)
{
  visited[mp(i, j)] = true;
  visited[mp(i, j)] = true;
  if(s[i+1][j] == s[i][j]+1){
    dfs(i+1, j, cnt); cnt[0]++;
  }
  if(s[i+1][j+1] == s[i][j]+1){
    dfs(i+1, j+1, cnt); cnt[1]++;
  }
  if(s[i][j+1] == s[i][j]+1){
    dfs(i,j+1, cnt); cnt[2]++;
  }
  if(s[i-1, j, cnt] == s[i][j]+1){
    dfs(i-1, j, cnt); cnt[3]++;
  }
  if(s[i-1][j-1] == s[i][j]+1){
    dfs(i-1, j-1, cnt); cnt[4]++;
  }
  if(s[i-1][j+1] == s[i][j]+1){
    dfs(i-1, j-1, cnt); cnt[5]++;
  }
  if(s[i][j-1] == s[i][j]+1){
    dfs(i, j-1, cnt); cnt[6]++;
  }
  if(s[i+1][j-1] == s[i][j]+1){
    dfs(i+1, j-1, cnt); cnt[7]++;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  int mx = -1;
  for(int i = 0; i < n; i++){
    for(int i = 0; i < m; i++){
      if(s[i][j] == 'A'){
        vector<int> cnt(8, 0);
        map<pair<int, int>, bool> visited;
        dfs(i, j, cnt);
        mx = max(*max_element(cnt.begin(), cnt.end()), mx);
      }
    }
  }
  cout << mx << '\n';
  return 0;
}

