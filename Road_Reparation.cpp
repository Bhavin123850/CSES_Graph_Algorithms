#include<bits/stdc++.h>
using namespace std;
#define ll long long
class DisjointSet{
    private:
    vector<int>parent,rank;
    public:
    DisjointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i = 1;i<=n;i++)
        {
            parent[i] = i;
        }
    }
    int findUpar(int node)
    {
        if(node == parent[node]) return node;
        return parent[node] = findUpar(parent[node]);
    }
    bool unionByRank(int u,int v)
    {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v) return false;
        if(rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else
        {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
        return true;
    }
    int numberOfComponent()
    {
        set<int>st;
        for(int i = 1;i<rank.size();i++)
        {
            int ulp = findUpar(i);
            st.insert(ulp);
        }
        return st.size();
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>>edges;
    for(int i = 0;i<m;i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        edges.push_back({c,{u,v}});
    }
    DisjointSet ds(n);
    sort(edges.begin(),edges.end());
    ll ans = 0ll;
    for(int i = 0;i<m;i++)
    {
        int c = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if(ds.unionByRank(u,v))
        {
            ans = ans + c*1ll;
        }
    }
    if(ds.numberOfComponent() > 1)
    {
        cout<<"IMPOSSIBLE"<<"\n";
        return 0;
    }
    cout<<ans<<"\n";
    return 0;
}