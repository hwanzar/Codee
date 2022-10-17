#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define pb push_back
const int N = 1e4 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int s)
{
    if (visited[s])
        return;
    visited[s] = true;
    // process node s
    for (auto u : adj[s])
    {
        dfs(u);
    }
}

int main()
{
<<<<<<< HEAD
=======
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        adj[i].pb(p);
        adj[p].pb(i); // add to graph.
    }
    int cntTree = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            cntTree++;
        }
    }
    cout << cntTree << '\n``';
>>>>>>> 9a75c3547cd740deef8ceed90fb71d76188022b9
}
