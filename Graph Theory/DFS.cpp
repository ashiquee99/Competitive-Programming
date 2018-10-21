#include <bits/stdc++.h>
using namespace std;
#define SIZE 1005
vector <int> g[SIZE];
bool vis[SIZE];
void dfs(int curr)
{
    vis[curr] = true;
    for(int i = 0; i<g[curr].size(); i++)
    {
        if(!vis[g[curr][i]])
        {
            dfs(g[curr][i]);
        }
    }
}

void Clear()
{
    memset(vis, false, sizeof(vis));
    for(int i=0; i<SIZE; i++) g[i].clear();
}

int main ()
{


    Clear();
    int n, u, v;
    cin>>n;
    for(int i = 0; i<n-1; i++)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i<=n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }

    return 0;
}
