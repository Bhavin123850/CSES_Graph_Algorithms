#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (int)(1e9+7)
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];
    for(int i = 0;i<m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
    }
    vector<ll>dist(n+1,LLONG_MAX),ways(n+1,0),minFlights(n+1,LLONG_MAX),maxFlights(n+1,LLONG_MIN);
    dist[1] = 0ll;
    ways[1] = 1ll;
    minFlights[1] = 0ll;
    maxFlights[1] = 0ll;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    pq.push({0ll,1});
    while(!pq.empty())
    {
        auto it = pq.top();
        int node = it.second;
        ll distance = it.first;
        pq.pop();
        if(distance > dist[node]) continue;
        for(auto neighbors : adj[node])
        {
            int adjNode = neighbors.first;
            int adjDist = neighbors.second;
            if(distance + 1ll*adjDist < dist[adjNode])
            {
                ways[adjNode] = ways[node];
                minFlights[adjNode] = minFlights[node] + 1;
                maxFlights[adjNode] = maxFlights[node] + 1;
                dist[adjNode] = distance + adjDist;
                pq.push({dist[adjNode],adjNode});
            }
            else if(distance + 1ll*adjDist == dist[adjNode])
            {
                ways[adjNode] = (ways[adjNode]%mod + ways[node]%mod)%mod;
                minFlights[adjNode] = min(minFlights[adjNode],minFlights[node]+1);
                maxFlights[adjNode] = max(maxFlights[adjNode],maxFlights[node]+1);
            }
        }
    }
    cout<<dist[n]<<" "<<ways[n]<<" "<<minFlights[n]<<" "<<maxFlights[n]<<"\n";
    return 0;
}