#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e2, di[4]={1, 0, -1, 0}, dj[4]={0, 1, 0, -1};
int k, m, n, si, sj, ti, tj, t;
int adj[mxN][mxN];
int dis[mxN][mxN] = {INT_MAX};

bool isok(int i, int j){
	return i>=0&&i<n&&j>=0&&j<n&&adj[i][j]!=-1;
}

int main()
{
	cin >> k;
	while(k--){
		si = 0, sj = 0;
		cin >> m >> n;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				cin >> adj[i][j];				
			}
		}
		cin >> ti >> tj >> t;
		queue<array<int, 2>> qu;
		qu.push({si, sj});
		dis[si][sj] = 0;
		while(qu.size()){
			auto u = qu.front(); qu.pop();
			for(int k = 0; k < 4; k++){
				int ni = u[0]+di[k], nj = u[1]+dj[k];
				if(!isok(ni, nj)){
					continue;
				}
				if(dis[u[0]][u[1]]+adj[u[0]][u[1]] < dis[ni][nj]){
					dis[ni][nj] = dis[u[0]][u[1]];
					qu.push({ni, nj});
				}
			}
			adj[u[0]][u[1]] = -1;
		}
		cout << t-dis[ti][tj] << '\n';
	}
	return 0;
}

I try to be normal. I try to smile, I try to make them feel the normal way. I try harder to be happy. All I do is try. I dont know if i'm going anywhere with this.
It all started with my shy nature, also the kind of behaviour to hide the worst of me. To hide my pain, To not allow anyone to know about me, TO let them know that i am okay and I am normal just like them, To get along with them and To not feel to different. I wanted to be like them, like normal and not having any weird problems, like
parents figthing, me crying in sleep, even not able to sleep. At first I tried to hide all this from my "school mates", so that they dont categorize me as weird or bad 
person, I thought they will judge me on the fact that my parents fights all night with me and elder brother trying to stop them uselessly, I thought they will judge me over my father working as a labour, I thought they will judge me because i didnt talked much to anyone in school, I thought they wil not talk to me if i do a single mistake, i use to think that other childrens are superior to me and i am just not like them, and i should try more achieve life like them, i just tried to be with them all the time, but in reality i didnt belong in betweeen them. today when i think how i become like this, i blame to my childhood maybe i am wrong about this but what could be the reason behind the kind of person i've become. its inside my head i cant control it, its the way i am thinking about the world all the time since childhood, i dont know how to entirely stop this kind of thoughts and just magically become a new person all of a sudden. That will not work, I always believed that i have something great to do since childhood, dont know why but just this feeling.
