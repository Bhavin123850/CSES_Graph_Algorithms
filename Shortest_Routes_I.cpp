#include<bits/stdc++.h>
#define ll long long
using namespace std;
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
    vector<ll>dist(n+1,LLONG_MAX);
    dist[1] = 0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    pq.push({0ll,1});
    while(!pq.empty())
    {
        auto it = pq.top();
        int node = it.second;
        ll distance = it.first;
        pq.pop();
        if(1ll*dist[node] < distance) continue;
        for(auto neighbors : adj[node])
        {
            int adjNode = neighbors.first;
            int adjDist = neighbors.second;
            if(dist[node] + 1ll*adjDist < dist[adjNode])
            {
                dist[adjNode] = dist[node] + 1ll*adjDist;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    for(int i = 1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<"\n";
    return 0;
}