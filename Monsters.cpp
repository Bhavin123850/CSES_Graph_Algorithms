#include<bits/stdc++.h>
using namespace std;
bool check(int i,int j,int n,int m)
{
    if(i < 0 || i >= n || j < 0 || j >= m) return false;
    return true;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    queue<pair<int,int>>q;
    pair<int,int>start;
    vector<vector<int>>distanceOfMonster(n,vector<int>(m,-1));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>v[i][j];
            if(v[i][j] == 'M')
            {
                q.push({i,j});
                distanceOfMonster[i][j] = 0;
            }
            else if(v[i][j] == 'A')
            {
                start = {i,j};
            }
        }
    }
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    char dir[] = {'D', 'U', 'R', 'L'};
    while(!q.empty())
    {
        auto it = q.front();
        int X = it.first;
        int Y = it.second;
        int distance = distanceOfMonster[X][Y];
        q.pop();
        for(int k = 0;k<4;k++)
        {
            int newX = X + dx[k];
            int newY = Y + dy[k];
            if(check(newX,newY,n,m) && (v[newX][newY] == 'A' || v[newX][newY] == '.') && distanceOfMonster[newX][newY] == -1)
            {
                distanceOfMonster[newX][newY] = distance + 1;
                q.push({newX,newY});
            }
        }
    }
    pair<int,int>end = {-1,-1};
    q.push(start);
    vector<vector<char>>parent(n,vector<char>(m,'N'));
    vector<vector<int>>distanceOfPlayer(n,vector<int>(m,-1));
    distanceOfPlayer[start.first][start.second] = 0;
    while(!q.empty())
    {
        auto it = q.front();
        int X = it.first;
        int Y = it.second;
        if(X == 0 || X == n-1 || Y == 0 || Y == m-1)
        {
            end = {X,Y};
        }
        int distance = distanceOfPlayer[X][Y];
        q.pop();
        for(int k = 0;k<4;k++)
        {
            int newX = X + dx[k];
            int newY = Y + dy[k];
            if(check(newX,newY,n,m) == false || v[newX][newY] == '#') continue;
            int u;
            if(distanceOfMonster[newX][newY] == -1) 
            {
                u = INT_MAX;
            }
            else
            {
                u = distanceOfMonster[newX][newY];
            }
            if(((distance + 1 < u)) && distanceOfPlayer[newX][newY] == -1)
            {
                distanceOfPlayer[newX][newY] = 1 + distance;
                parent[newX][newY] = dir[k];
                q.push({newX,newY});
            }
        }
    }
    if(end.first == -1 && end.second == -1)
    {
        cout<<"NO"<<"\n";
        return 0;
    }
    string ans = "";
    int X = end.first;
    int Y = end.second;
    while(parent[X][Y] != 'N')
    {
        ans += parent[X][Y];
        if(parent[X][Y] == 'U')
        {
            X++;
        }
        else if(parent[X][Y] == 'D')
        {
            X--;
        }
        else if(parent[X][Y] == 'L')
        {
            Y++;
        }
        else
        {
            Y--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<"YES"<<"\n";
    cout<<ans.length()<<"\n";
    cout<<ans<<"\n";
    return 0;
}