#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define _io                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
#define fi first
#define se second
#define MAXN 400005
#define INF 1e9

vii DSK[MAXN];
int dist[MAXN];
int vi[MAXN];

int prim(int n)
{
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        vi[i] = false;
    }
    priority_queue<ii, vii, greater<ii>> heap;
    heap.push({0, 0});
    dist[0] = 0;

    int u, v, w;
    int cnt = 0;

    while (!heap.empty())
    {
        ii top = heap.top();
        heap.pop();
        u = top.se;

        if (vi[u])
            continue;

        vi[u] = true;
        cnt++;
        for (ii nei : DSK[u])
        {
            v = nei.fi;
            w = nei.se;
            if (!vi[v] && dist[v] > w)
            {
                dist[v] = w;
                heap.push({w, v});
            }
        }
    }
    int total_weight = 0;
    for (int i = 0; i < n; i++)
    {
        total_weight += dist[i];
    }
    return total_weight;
}

int main()
{
    _io int n, m;
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
        {
            DSK[i].clear();
        }
        if (n == 0)
            break;
        int u, v, c, total = 0;
        while (m--)
        {
            cin >> u >> v >> c;
            DSK[u].pb({v, c});
            DSK[v].pb({u, c});
            total += c;
        }
        cout << total - prim(n) << '\n';
    }
}
