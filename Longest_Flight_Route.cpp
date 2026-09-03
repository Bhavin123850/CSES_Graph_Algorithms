#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    vector<int> inDegree(n + 1, 0);

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        inDegree[v]++;
    }

    vector<int> parent(n + 1, -1);
    vector<int> dist(n + 1, 0);

    dist[1] = 1;
    parent[1] = 1;

    queue<int> q;

    for(int i = 1; i <= n; i++)
    {
        if(inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto neighbors : adj[node])
        {
            if(dist[node] != 0 &&
               dist[neighbors] < dist[node] + 1)
            {
                dist[neighbors] = dist[node] + 1;
                parent[neighbors] = node;
            }

            inDegree[neighbors]--;

            if(inDegree[neighbors] == 0)
            {
                q.push(neighbors);
            }
        }
    }

    if(dist[n] == 0)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> ans;

    int curr = n;

    while(curr != 1)
    {
        ans.push_back(curr);
        curr = parent[curr];
    }

    ans.push_back(1);

    reverse(ans.begin(), ans.end());

    cout << ans.size() << "\n";

    for(auto node : ans)
    {
        cout << node << " ";
    }

    cout << "\n";

    return 0;
}