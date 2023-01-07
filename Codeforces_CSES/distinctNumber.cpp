#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int a[200000];
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[i + 1])
        {
            cnt++;
        }
    }
}