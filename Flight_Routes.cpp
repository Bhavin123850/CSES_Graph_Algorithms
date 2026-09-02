#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int>>adj[n+1];
    for(int i = 0;i<m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
    }
    vector<int>cnt(n+1,0);
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
    pq.push({0ll,1});
    vector<ll>ans;
    while(!pq.empty())
    {
        auto it = pq.top();
        int node = it.second;
        ll distance = it.first;
        pq.pop();
        if(cnt[node] >= k) continue;
        cnt[node]++;
        if(node == n)
        {
            ans.push_back(distance);
            if(cnt[node] == k) break;
        }
        for(auto neighbors : adj[node])
        {
            int adjNode = neighbors.first;
            int adjDist = neighbors.second;
            pq.push({distance+1ll*adjDist,adjNode});
        }
    }
    for(auto it : ans)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
    return 0;
}