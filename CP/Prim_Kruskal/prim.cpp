#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

const int INF = 1e9; // 1ty
typedef pair<int, int> pii;
#define pb push_back
vector<int> dist, path;
vector<bool> visited;
vector<vector<pii>> adj; // adjacent lisst;
int n, m;

bool prim()
{
    dist.assign(n, INF);
    path.assign(n, -1);
    visited.assign(n, false);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    dist[0] = 0;

    int u, v, w;
    int cnt = 0;

    while (!pq.empty())
    {
        pii tmp = pq.top();
        pq.pop();
        u = tmp.second;
        if (visited[u])
            continue;
        visited[u] = true;
        cnt++;
        for (pii nei : adj[u])
        {
            v = nei.first;
            w = nei.second;
            if (!visited[v] && dist[v] > w)
            {
                dist[v] = w;
                path[v] = u;
                pq.push({w, v});
            }
        }
    }
    return cnt == n; // true or false?
}

int main()
{
    cin >> n >> m;

    adj.assign(n, vector<pii>());
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w}); // bidirectional
    }

    if (!prim())
        cout << "Graph is not connected\n";
    else
    {
        int mst = 0;
        for (int i = 0; i < n; i++)
        {
            mst += dist[i];
            cout << "MST: " << mst << "\n";
        }
    }
    return 0;
}