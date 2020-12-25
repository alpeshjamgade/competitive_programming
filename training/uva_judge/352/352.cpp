#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e3, di[8]={-1, -1, -1, 0, 0, 1, 1, 1}, dj[8]={-1, 0, 1, -1, 1, -1, 0, 1};
int n, m;
string s[mxN];


bool isok(int i, int j){
    return i>=0 && i<n && j>=0 && j <n && s[i][j] == '1';
}
void dfs(int i, int j){

    s[i][j] = '0';
    for(int k = 0; k < 8; k++){
        int ni = di[k]+i, nj = dj[k]+j;
        if(isok(ni, nj)){
            dfs(ni, nj);
        }
    }
}

void init(){
    for(int i = 0; i < n; i++){
        s[i].clear();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int test = 0;
    while(cin >> n){
        test++;
        init();
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(s[i][j] == '1'){
                    dfs(i, j); cnt++;
                }
            }
        }
        cout << "Image number " << test << " contains " << cnt << " war eagles.\n";
    }
    return 0;
}
