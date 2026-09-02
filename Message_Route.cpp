#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i = 0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>parent(n+1,-1),visited(n+1,0);
    queue<int>q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                visited[it] = 1;
                parent[it] = node;
                q.push(it);
            }
        }
    }
    if(parent[n] == -1)
    {
        cout<<"IMPOSSIBLE\n";
    }
    else
    {
        vector<int>path;
        int node = n;
        while(node != -1)
        {
            path.push_back(node);
            node = parent[node];
        }
        reverse(path.begin(),path.end());
        cout<<path.size()<<"\n";
        for(auto it : path)
        {
            cout<<it<<" ";
        }
        cout<<"\n";
    }

    return 0;
}