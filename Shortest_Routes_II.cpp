#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<ll>>dist(n+1,vector<ll>(n+1,LLONG_MAX));
    for(int i = 0;i<m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        dist[u][v] = c;
        dist[v][u] = c;
    }
    for(int i = 1;i<n+1;i++) dist[i][i] = 0ll;
    for(int via = 1;via<n+1;via++)
    {
        for(int i = 1;i<n+1;i++)
        {
            for(int j = 1;j<n+1;j++)
            {
                if(dist[i][via] != LLONG_MAX && dist[via][j] != LLONG_MAX)
                dist[i][j] = min(dist[i][j],dist[i][via]+dist[via][j]); 
            }
        }
    } 
    for(int i= 0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        if(dist[a][b] == LLONG_MAX)
        {
            cout<<-1<<"\n";
        }
        else
        {
            cout<<dist[a][b]<<"\n";
        }
    }
    return 0;
}