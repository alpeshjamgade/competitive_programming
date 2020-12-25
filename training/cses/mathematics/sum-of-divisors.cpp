#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mxN = 1e5;
int M1 = 1e9+7;

ll c2(ll n){
	return n%M1*((n-1)%M1)%M1*((M+1)/2)%M1;
}

int main()
{
	ll n, ans = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		ll r = n/(n/i);
		ans += n/i%M1*(c2(r+1)-c2(i)+M1)%M1; 
		i = r;
	}
	cout << ans;
	return 0;
}

