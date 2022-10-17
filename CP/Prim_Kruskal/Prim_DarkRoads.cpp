#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define _io                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define pb push_back
#define pii pair<int, int>
const int INF = 1e9; // 1ty
const int MAXN = 400005;

vector<pii> adj[MAXN];
int dist[MAXN];
bool visited[MAXN];
int path[MAXN];

int prim(int n)
{
    // dist.assign(n, INF);
    // path.assign(n, -1);
    // visited.assign(n, false);
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = false;
    }
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
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += dist[i];
    }
    return total;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int n, m;
    while (cin >> n >> m)
    {
 
        for (int i = 0; i < n; i++)
            adj[i].clear();
        if (n == 0)
            break;
        int u, v, w, totall = 0;
        while (m--)
        {
            cin >> u >> v >> w;
            adj[u].pb({v, w});
            adj[v].pb({u, w});
            totall += w;
        }
        cout << totall - prim(n) << '\n';

        return 0;
    }
}