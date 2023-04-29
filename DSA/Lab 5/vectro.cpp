#include <bits/stdc++.h>
using namespace std;
#define outtext freopen("output.txt", "w", stdout)
#define _io                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int main()
{
    vector<int> v = {55, 1, 2, 3, 4, 5, 6, 7};
    v.erase(v.begin(), v.end() - 1);
    v.clear();
    cout << v[0];
    return 0;
}