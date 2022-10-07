#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define pb push_back
const int MAXN = 1010;

int n, m; // vertice, edge
int neighborX[4] = {0, 0, 1, -1};
int neighborY[4] = {1, -1, 0, 0};
int vis[MAXN][MAXN];
char3333333333 grid[MAXN][MAXN];

int isValid(int y, int x)
{
    if (y < 0)
    {
        return false;
    }
    if (x < 0)
        return false;
    if (y >= n)
        return false;
    if (x >= n)
        return false;
    if (grid[y][x] == '#')
        return false;
    return true;
}

void DFS(int y, int x)
{
    vis[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int newX = x + neighborX[i];
        int newY = y + neighborY[i];
        if (isValid(newY, newX))
        {
            if(!vis[newY][newX]){
                DFS(newY,newX);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    }


    return 0;
}