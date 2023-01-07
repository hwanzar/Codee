int n; // Số lượng đỉnh của đồ thị
int d[maxN], par[maxN];
bool visit[maxN];
vector <int> g[maxN];

void bfs(int s) { // Với s là đỉnh xuất phát (đỉnh nguồn)
    fill_n(d, n + 1, 0);
    fill_n(par, n + 1, -1);
    fill_n(visit, n + 1, false);

    queue <int> q;
    q.push(s);
    visit[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (!visit[v]) {
                d[v]     = d[u] + 1;
                par[v]   = u;
                visit[v] = true;
                q.push(v);
            }
        }
    }
}
