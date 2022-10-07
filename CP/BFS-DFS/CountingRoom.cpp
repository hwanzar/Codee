#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define pb push_back
int neighborX[4] = {0, 0, 1, -1};
int neighborY[4] = {1, -1, 0, 0};
const int N = 1010;
char grph[N][N];
bool visited[N][N];
int n, m, ans = 0;

bool check(int y, int x)
{
    if (y < 0)
        return false;
    if (x < 0)
        return false;
    if (y >= n)
        return false;
    if (x >= m)
        return false;
    if (grph[y][x] == '#')
        return false;
    return true;
}

void DFS(int y, int x)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int newX = x + neighborX[i];
        int newY = y + neighborY[i];
        if (check(newY, newX))
        {
            if (!visited[newY][newX])
            {
                DFS(newY, newX);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grph[i][j];
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grph[i][j] == '.' && !visited[i][j])
            {
                DFS(i, j);
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
