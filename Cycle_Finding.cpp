#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n,m;
    cin>>n>>m;
    vector<ll>dist(n+1,0);
    dist[1] = 0ll;
    vector<pair<pair<int,int>,int>>edges;
    vector<int>adj[n+1];
    for(int i = 0;i<m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back(v);
        edges.push_back({{u,v},c});
    }
    vector<int>parent(n+1);
    for(int i = 0;i<=n;i++)
    {
        parent[i] = i;
    }
    for(int k = 1;k<n;k++)
    {
        for(int i = 0;i<m;i++)
        {
            int u = edges[i].first.first;
            int v = edges[i].first.second;
            int c = edges[i].second;
            if(dist[u] != LLONG_MAX && dist[u] + 1ll*c < dist[v])
            {
                dist[v] = dist[u] + 1ll*c;
                parent[v] = u;
            }
        }
    }
    int lastUpdatedNode = -1;
    for(int i = 0;i<m;i++)
    {
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int c = edges[i].second;
        if(dist[u] != LLONG_MAX && dist[u] + 1ll*c < dist[v])
        {
            parent[v] = u;
            dist[v] = dist[u] + 1ll*c;
            lastUpdatedNode = v;
        }
    }
    if(lastUpdatedNode == -1)
    {
        cout<<"NO"<<"\n";
        return 0;
    }
    int x = lastUpdatedNode;
    for(int i = 0;i<n;i++)
    {
        x = parent[x];
    }
    vector<int>path;
    int curr = x;
    path.push_back(curr);
    curr = parent[curr];
    while(curr != x)
    {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(x);
    reverse(path.begin(),path.end());
    cout<<"YES"<<"\n";
    for(auto it : path)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
    return 0;
}