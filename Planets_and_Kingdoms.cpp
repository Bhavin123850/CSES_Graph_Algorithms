#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>&visited,vector<int>adj[],stack<int>&st)
{
    visited[node] = 1;
    for(auto neighbors : adj[node])
    {
        if(visited[neighbors] == 0)
        dfs(neighbors,visited,adj,st);
    }
    st.push(node);
}
void dfs2(int node,vector<int>&visited,vector<int>adj[],vector<int>&component)
{
    visited[node] = 1;
    component.push_back(node);
    for(auto neighbors : adj[node])
    {
        if(visited[neighbors] == 0)
        dfs2(neighbors,visited,adj,component);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1],revAdj[n+1];
    for(int i = 0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }
    stack<int>st;
    vector<int>visited(n+1,0);
    for(int i = 1;i<=n;i++)
    {
        if(visited[i] == 0)
        {
            dfs(i,visited,adj,st);
        }
    }
    for(int i = 1;i<=n;i++) visited[i] = 0;
    vector<vector<int>>SSC;
    while(!st.empty())
    {
        if(visited[st.top()] == 0)
        {
            vector<int>component;
            dfs2(st.top(),visited,revAdj,component);
            SSC.push_back(component);
        }
        st.pop();
    }
    map<int,int>mp;
    for(int i = 0;i<SSC.size();i++)
    {
        for(auto it : SSC[i])
        {
            mp[it] = i+1;
        }
    }
    cout<<SSC.size()<<"\n";
    for(int i = 1;i<=n;i++)
    {
        cout<<mp[i]<<" ";
    }
    cout<<"\n";
    return 0;
}