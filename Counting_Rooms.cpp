#include<bits/stdc++.h>
using namespace std;
bool check(int i,int j,int n,int m)
{
    if(i<0 || j<0 || i>=n || j>=m)
    {
        return false;
    }
    return true;
}
void dfs(int i,int j,vector<vector<char>>&v,vector<vector<bool>>&visited)
{
    visited[i][j] = true;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    for(int k = 0;k<4;k++)
    {
        int newX = i + dx[k];
        int newY = j + dy[k];   
        if(check(newX,newY,v.size(),v[0].size()) && !visited[newX][newY] && v[newX][newY] == '.')
        {               
            dfs(newX,newY,v,visited);
        }  
    }                      
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    int numberOfRooms = 0;
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(!visited[i][j] && v[i][j] == '.')
            {
                dfs(i,j,v,visited);
                numberOfRooms++;
            }
        }
    }
    cout<<numberOfRooms<<endl;
}