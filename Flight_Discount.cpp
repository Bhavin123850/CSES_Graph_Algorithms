#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> dijkstra(int node,vector<pair<int,int>>adj[],int n)
{
    vector<ll>dist(n+1,LLONG_MAX);
    dist[node] = 0ll;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    pq.push({0ll,node});
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
                dist[adjNode] = distance + 1ll*adjDist;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];
    vector<pair<int,int>>revAdj[n+1];
    vector<pair<pair<int,int>,int>>edges;
    for(int i = 0;i<m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        revAdj[v].push_back({u,c});
        edges.push_back({{u,v},c});
    }
    vector<ll>distFromStart = dijkstra(1,adj,n);
    vector<ll>distFromEnd = dijkstra(n,revAdj,n);
    ll mn = LLONG_MAX;
    for(auto it : edges)
    {
        int u = it.first.first;
        int v = it.first.second;
        int c = it.second;
        if(distFromStart[u] != LLONG_MAX && distFromEnd[v] != LLONG_MAX)
        mn = min(mn,distFromStart[u] + distFromEnd[v] + 1ll*(c/2));
    }
    cout<<mn<<"\n";
    return 0;
}