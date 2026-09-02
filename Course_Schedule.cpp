#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>inDegree(n+1,0);
    vector<int>adj[n+1];
    for(int i = 0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        inDegree[v]++;
        adj[u].push_back(v);
    }
    queue<int>q;
    for(int i = 1;i<=n;i++)
    {
        if(inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty())
    {
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for(auto neighbors : adj[node])
        {
            inDegree[neighbors]--;
            if(inDegree[neighbors] == 0)
            {
                q.push(neighbors);
            }
        }
    }
    if(ans.size() != n)
    {
        cout<<"IMPOSSIBLE"<<"\n";
        return 0;
    }
    for(auto it : ans) cout<<it<<" ";
    cout<<"\n";
    return 0;
}