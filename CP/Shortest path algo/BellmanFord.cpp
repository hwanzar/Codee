#include <bits/stdc++.h>
using namespace std;



for (int i = 1; i <= n; i++)
    distance[i] = INF;
distance[x] = 0;
for (int i = 1; i <= n - 1; i++)
{
    for (auto e : edges)
    {
        int a, b, w;
        tie(a, b, w) = e;
        distance[b] = min(distance[b], distance[a] + w);
    }
}
for (int)