#include<bits/stdc++.h>
#define ll long long
using namespace std;
void dfs(int node,vector<int>&visited,vector<int>adj[])
{
    visited[node] = 1;
    for(auto neighbors : adj[node])
    {
        if(visited[neighbors]) continue;
        dfs(neighbors,visited,adj);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<pair<int,int>,int>>edges;
    vector<int>adj[n+1];
    for(int i = 0;i<m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        edges.push_back({{u,v},c});
        adj[v].push_back(u);
    }
    vector<int>visited(n+1,0);
    dfs(n,visited,adj);
    vector<ll>dist(n+1,LLONG_MIN);
    dist[1] = 0;
    for(int k = 1;k<n;k++)
    {
        for(int i = 0;i<edges.size();i++)
        {
            int u = edges[i].first.first;
            int v = edges[i].first.second;
            int c = edges[i].second;
            if(dist[u] != LLONG_MIN && dist[v] < dist[u] + c)
            {
                dist[v] = dist[u] + c;
            }
        }
    }
    for(int i = 0;i<edges.size();i++)
    {
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int c = edges[i].second;
        if(dist[u] != LLONG_MIN && dist[v] < dist[u] + c)
        {
            dist[v] = dist[u] + c;
            if(visited[u] || visited[v]) 
            {
                cout<<-1<<"\n";
                return 0;
            }
        }
    }
    cout<<dist[n]<<"\n";
    return 0;
}