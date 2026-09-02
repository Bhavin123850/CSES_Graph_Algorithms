#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int>& visited,
         vector<int>& pathVisited,
         vector<int>& path,
         vector<int> adj[],
         vector<int>& parent)
{
    visited[node] = 1;
    pathVisited[node] = 1;
    path.push_back(node);

    for(auto neighbors : adj[node])
    {
        if(!visited[neighbors])
        {
            parent[neighbors] = node;

            bool flag = dfs(neighbors, visited, pathVisited,
                            path, adj, parent);

            if(flag)
                return true;
        }
        else if(pathVisited[neighbors])
        {
            // Closing edge of the cycle
            parent[neighbors] = node;
            path.push_back(neighbors);
            return true;
        }
    }

    path.pop_back();
    pathVisited[node] = 0;

    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> visited(n + 1, 0);
    vector<int> pathVisited(n + 1, 0);
    vector<int> path;
    vector<int> parent(n + 1, 0);

    bool flag = false;

    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            flag = dfs(i, visited, pathVisited,
                       path, adj, parent);

            if(flag)
                break;
        }
    }

    if(!flag)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int node = path.back();

    vector<int> ans;
    ans.push_back(node);

    int curr = parent[node];

    while(curr != node)
    {
        ans.push_back(curr);
        curr = parent[curr];
    }

    ans.push_back(node);

    reverse(ans.begin(), ans.end());

    cout << ans.size() << "\n";

    for(auto x : ans)
        cout << x << " ";

    cout << "\n";
}