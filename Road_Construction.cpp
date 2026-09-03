#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    private:
    vector<int>parent,size;
    public:
    DisjointSet(int n)
    {
        parent.resize(n+1);
        size.resize(n+1,1);
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
    bool unionBySize(int u,int v)
    {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v) return false;
        if(size[ulp_u] >= size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        return true;
    }
    int getComponentSize(int node)
    {
        int ulp = findUpar(node);
        return size[ulp];
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    DisjointSet ds(n);
    int count = n;
    int mx = 1;
    for(int i = 0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        bool flage = ds.unionBySize(u,v);
        if(flage)
        {
            count--;
            int sz = ds.getComponentSize(u);
            mx = max(mx,sz);
        }
        cout<<count<<" "<<mx<<"\n";
    }
    return 0;
}