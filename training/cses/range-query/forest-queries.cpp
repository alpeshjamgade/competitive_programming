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


//DP approach;
const int mxN = 1e3;
int n, q;
string s[mxN];
ll arr[mxN+1][mxN+1];

void L()
{
	cin >> n >> q;
	for(int i = 0; i < n; i++){
		cin >> s[i];
		for(int j=0; j < n; j++){
			if(s[i][j]=='*'){
				arr[i+1][j+1]++;
			}
		}
		for(int j = 0; j < n; j++){
			arr[i+1][j+1] += arr[i+1][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			arr[i+1][j+1] += arr[i][j+1];
		}
	}

	int x1, y1, x2, y2;
	while(q--){
		cin >> x1 >> y1 >> x2 >> y2;
		cout << arr[x2][y2] - arr[x2][y1-1] - arr[x1-1][y2] +arr[x1-1][y1-1] << '\n'; //IMP ***
	}
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);


  L();
  return 0;
}
