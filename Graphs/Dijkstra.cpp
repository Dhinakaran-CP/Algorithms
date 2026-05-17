#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;
struct Edge{
   int to;
   int weight; 
};

struct Node{
    int id;
    int dist;

    bool operator<(const Node& other)const{
        return dist > other.dist;
    }
};

vector<ll> dijkstra(int source , int n , vector<vector<Edge>>&adj){
    vector<ll>dist(n+1,INF);
    dist[source]=0;
    pq.push({source,0});
    while(!pq.empty()){
        Node current = pq.top();
        pq.pop();

        int u = current.id;
        int d = current.dist;

        if (d > dist[u])continue;

        for (auto& edge:adj[u]){
            int v = edge.to;
            int weight = edge.weight;

            if (dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
                pq.push({v,dist[v]});
            } 
        }
    }

    return dist;
}

int main(){
    ios_base::sync_with_studio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;

    vector<vector<Edge>>adj(n+1);
    for (int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        int w = 1;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int source = 1;

    vector<ll>dist = dijkstra(source, n , adj);
    for (int i=1;i<=n;i++){
        if (dist[i]!=INF){
            cout << dist[i] <<" ";
        }
        else cout << "INF" <<" ";
    }
}
