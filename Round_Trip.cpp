#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,int parent,vector<int>&visited,vector<int>&path,vector<int>adj[])
{
    visited[node] = 1;
    path.push_back(node);
    for(auto it : adj[node])
    {
        if(it == parent) continue;
        if(!visited[it])
        {
            bool flage = dfs(it,node,visited,path,adj);
            if(flage) return true;
        }
        else if(visited[it])
        {
            path.push_back(it);
            return true;
        }
    }
    path.pop_back();
    return false;
}
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
    vector<int>path,visited(n+1,0);
    for(int i = 1;i<=n;i++)
    {
        if(visited[i] == true) continue;
        bool flage = dfs(i,-1,visited,path,adj);
        if(flage) 
        {
            vector<int>x;
            int oo = path.size();
            x.push_back(path[oo-1]);
            int j = oo-2;
            while(path[j] != path[oo-1])
            {
                x.push_back(path[j]);
                j--;
            }
            x.push_back(path[oo-1]);
            cout<<x.size()<<"\n";
            for(auto it : x)
            {
                cout<<it<<" ";
            }
            cout<<"\n";
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<"\n";
    return 0;
}