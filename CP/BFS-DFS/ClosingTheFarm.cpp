#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5;
vector<bool> visited(maxN);
vector<vector<int>> adj(maxN);
vector<int> closed(maxN);

int nodes = 0;

void dfs(int s)
{
    if (visited[s] || nodes)
    {
        return;
    }
    node++;
    visited[s] = true;  
    for (auto u : adj[s])
    {
        dfs(u);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u;
        cin >> u;
        int v;
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ord(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ord[i];
    }
    dfs(1);
    // traverse all the dfs
}