#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m));

    pair<int, int> start, end;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];

            if (v[i][j] == 'A')
                start = {i, j};

            else if (v[i][j] == 'B')
                end = {i, j};
        }
    }

    queue<pair<int, int>> q;

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // Stores which direction was used to reach each cell
    vector<vector<char>> parent(n, vector<char>(m));

    q.push(start);
    visited[start.first][start.second] = true;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    char dir[] = {'D', 'U', 'R', 'L'};

    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int newX = current.first + dx[k];
            int newY = current.second + dy[k];

            if (newX >= 0 && newY >= 0 &&
                newX < n && newY < m &&
                !visited[newX][newY] &&
                v[newX][newY] != '#')
            {
                visited[newX][newY] = true;

                parent[newX][newY] = dir[k];

                q.push({newX, newY});
            }
        }
    }

    if (!visited[end.first][end.second])
    {
        cout << "NO\n";
        return 0;
    }

    string path = "";

    pair<int, int> current = end;

    // Move backward from B to A
    while (current != start)
    {
        char d = parent[current.first][current.second];

        path += d;

        if (d == 'D')
            current.first--;

        else if (d == 'U')
            current.first++;

        else if (d == 'R')
            current.second--;

        else if (d == 'L')
            current.second++;
    }

    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.length() << "\n";
    cout << path << "\n";

    return 0;
}