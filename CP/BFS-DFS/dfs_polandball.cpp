#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define pb push_back

int N, M;
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
    asjkfhkjasfadshfklasjf
}
