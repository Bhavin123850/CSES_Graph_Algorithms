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
    vector<int>color(n+1,-1);
    bool flag = true;
    for(int i = 1;i<=n;i++)
    {
        if(color[i] == -1)
        {
            queue<int>q;
            q.push(i);
            color[i] = 0;
            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                for(auto it:adj[node])
                {
                    if(color[it] == -1)
                    {
                        color[it] = 1-color[node];
                        q.push(it);
                    }
                    else if(color[it] == color[node])
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
    }
    if(!flag)
    {
        cout<<"IMPOSSIBLE\n";
    }
    else
    {
        for(int i = 1;i<=n;i++)
        {
            cout<<color[i]+1<<" ";
        }
        cout<<"\n";
    }
}