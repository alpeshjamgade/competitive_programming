#include <bits/stdc++.h>
using namespace std;

const int mxN = 500;
int total_fire_stations, cities, total_intersections;
string line;
vector<array<int, 2>> adj[mxN];

int Dijkstra(vector<int>& fire_stations){

    vector<int> distance(total_intersections, mxN);
    vector<bool> vis(total_intersections, false);
    priority_queue<array<int,2>, vector<array<int,2>>, greater<array<int, 2>>> pq;
    
    for(int station : fire_stations){
        pq.push({0, station});
        distance[station] = 0;
    }

    // start;
    while(pq.size()){
        array<int, 2> uu = pq.top();
        pq.pop();
        int u = uu[1];
        if(vis[u]) continue;
        vis[u] = 1;
        for(array<int, 2> vv : adj[u]){
            int v = vv[0], w = vv[1];
            if(distance[v] > distance[u] + w){
                distance[v] = distance[u]+w;
                pq.push({distance[v], v});
            }
        }
    }

    // got all the distances;
    // Find the smallest node with largest distance from the nearest fire station.
    int longest_distance = 0;
    int intersection_point = INT_MAX;
    cout << '\n';
    for(int i = 0; i < total_intersections; i++){
        cout << distance[i] << ' ';
        if(distance[i] > longest_distance){
            longest_distance = distance[i];
            intersection_point = i+1;
        }
        // else if( distance[i] == longest_distance){
        //     intersection_point = min(intersection_point, i+1);
        // }
    }
    cout << '\n';
    return intersection_point;
}

void init(){
    for(int i = 0; i < total_intersections; i++){
        adj[i].clear();
    }
}

int solve_testcase(){
    cin >> total_fire_stations >> total_intersections;
    init();
    vector<int> fire_stations;
    for(int i = 0, station_number; i < total_fire_stations; i++){
        cin >> station_number;
        fire_stations.emplace_back(station_number-1);
    }
    cin.ignore();
    while(1){
        getline(cin, line);
        if(cin.eof() || line == ""){
            break;
        }
        int a, b, c;
        stringstream stream(line);
        stream >> a;
        stream >> b;
        stream >> c;
        a--, b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    return Dijkstra(fire_stations);
}

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_cases;
    cin >> test_cases;
    for(int t = 1; t <= test_cases; t++){
        int answer = solve_testcase();
        if(t == 1){
            cout << answer;
        }else{
            cout << '\n' << answer;
        }
    }
    return 0;
}