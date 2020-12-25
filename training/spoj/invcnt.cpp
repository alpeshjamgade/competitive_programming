#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll merge(vector<int> &arr, vector<int> &tmp, int L, int M, int R){
	int i = L, j = M+1, k = L;
	ll cnt = 0;
	while(i <= M && j <= R){
		if(arr[i] <= arr[j]){
			tmp[k++] = arr[i++];
		}
		else{
			tmp[k++] = arr[j++];
			cnt += (M-i+1);
		}
	}
	while(i <= M){
		tmp[k++] = arr[i++];
	}
	for(int i = L; i <= R; i++){
		arr[i] = tmp[i];
	}
	return cnt;
}

ll merge_sort(vector<int>&arr, vector<int> &tmp, int L, int R){
	if(L == R) return 0;
	int M = L +(R-L)/2;
	cnt += merge_sort(arr, tmp, L, M);
	cnt += merge_sort(arr, tmp, M+1, R);
	cnt += merge(arr, tmp, L, M, R);
	return cnt;
}

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> arr(n), tmp(n);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
			tmp[i] = arr[i];
		}
		cout << merge_sort(arr, tmp, 0, n-1) << '\n';
	}
	return 0;
}
