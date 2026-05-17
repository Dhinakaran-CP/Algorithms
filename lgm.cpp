#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;
#define INF (int)1e18
#define f first
#define s second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using vll = vector<long long>;
using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;
ll MOD = 1e9+7;
constexpr int inf = 1e18;
#define pb push_back
#define pf push_front
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rep(i,n) for (int i=0;i<(n);i++)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


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
    priority_queue<Node>pq;
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


void solve(){
    int n , m,k;
    cin >> n >> m>>k;
    vll v(n+1);
    rep(i,n)cin >> v[i+1];

    // group the types in a map for look up

    map<int,vector<int>>mp;

    rep(i,n){
        int x = v[i+1];
        mp[x].pb(i+1);
    }

    vector<vector<Edge>>adj(n+1);
    rep(i,m){
        int a,b;
        cin >>a >> b;
        adj[a].pb({b,1});
        adj[b].pb({a,1});
    }


    

    // Apply dijkstra for single source shortest path 

    vll dist = dijkstra(1,n,adj);

    
    
    for (auto type:mp){
        vector<int>&nodes = type.second;
        int maxi = 0;
        for (auto i:nodes){
            maxi = max(maxi,dist[i]);
        }

        cout << maxi <<" ";
    }


}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t =1;

    
    //cin >>t;

    while(t--){
    solve();
    }
    return 0;
}