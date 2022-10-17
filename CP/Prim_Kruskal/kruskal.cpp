#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int MAXN = 1e5; // 1e9
int parent[MAXN];
int Rank[MAXN]; // for DSU

vector<piii> edges; // elist kruskal.

int n, m;

void makeSet(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        Rank[i] = i;
    }
}
int findSet(int u)
{
    if (parent[u] != u)
    {
        parent[u] = findSet(parent[u]);
    }
    return parent[u];
}

bool unionSet(int u, int v)
{
    int pu = findSet(u);
    int pv = findSet(v);
    if (pu == pv)
        return false;

    if (Rank[pu] > Rank[pv])
    {
        parent[pv] = pu;
    }
    else if (Rank[pu] < Rank[pv])
        parent[pu] = pv;
    else
    {
        parent[pv] = pu;
        Rank[pu]++;
    }
    return true;
}

int kruskal()
{
    int mst = 0;
    int cnt = 0;

    sort(edges.begin(), edges.end());
    makeSet(n);

    for (int u, v, w, i = 0; i < m; i++)
    {
        u = edges[i].second.first;
        v = edges[i].second.second;
        w = edges[i].first;
        if (unionSet(u, v))
        {
            cnt++;
            mst += w;
        }
    }
    return cnt == n - 1 ? mst : -1;
}

int main()
{
    cin >> n >> m;
    for (int u, v, w, i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        edges.push_back(make_pair(w, make_pair(u, v)));
    }
    int mst = kruskal();
    //cout << mst << '\n';
    if (mst == -1)
    {
        cout << "The graph is not connected\n";
    }
    else
        cout << mst << '\n';

    return 0;
}