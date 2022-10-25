#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> path;
vector<bool> visited;

void bfs(int s){
    int sz = adj.size();
    path.assign(sz,-1);
    visited.assign(sz, false);
    queue<int> q;



    q.push(s);
    visited[s] = true;
}


int main(){

} 