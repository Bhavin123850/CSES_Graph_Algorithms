#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    private:
    vector<int>rank,parent;
    public:
    DisjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i = 0;i<=n;i++)
        {
            parent[i]  = i;
        }
    }
    int findUpar(int node)
    {
        if(node == parent[node])
        {
            return node;
        }
        return parent[node] = findUpar(parent[node]);
    }
    bool unionByRank(int u,int v)
    {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v)
        {
            return false;
        }
        if(rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
        return true;

    }
    vector<int> getUltimateParent()
    {
        vector<int>ultimateParent;
        set<int>st;
        for(int i = 1;i<parent.size();i++)
        {
            st.insert(findUpar(i));
        }
        for(auto it:st)
        {
            ultimateParent.push_back(it);
        }
        return ultimateParent;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    DisjointSet ds(n);
    for(int i = 0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        ds.unionByRank(u,v);
    }
    vector<int>ultimateParent = ds.getUltimateParent();
    cout<<ultimateParent.size()-1<<"\n";
    for(int i = 1;i<ultimateParent.size();i++)
    {
        cout<<ultimateParent[i-1]<<" "<<ultimateParent[i]<<"\n";
    }
    return 0;
}