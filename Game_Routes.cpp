#include<bits/stdc++.h>
using namespace std;
#define mod (int)(1e9+7)
#define ll long long
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    vector<int>inDegree(n+1,0);
    for(int i = 0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        inDegree[v]++;
    }
    queue<int>q;
    vector<int>ways(n+1,0);
    for(int i = 1;i<=n;i++)
    {
        if(inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    ways[1] = 1;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto neighbors : adj[node])
        {
            ways[neighbors] = (ways[neighbors]%mod + ways[node]%mod)%mod;
            inDegree[neighbors]--;
            if(inDegree[neighbors] == 0)
            {
                q.push(neighbors);
            }
        }
    }
    cout<<ways[n]<<"\n";
    return 0;
}