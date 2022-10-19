#include <bits/stdc++.h>
using namespace std;
// two pointer

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int inp;
    cin >> inp;

    while (inp--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        string s;
        cin >> s;

        bool flag = true;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {

                if (a[i] == a[j])
                {
                    if (s[i] != s[j])
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        string ans = (flag) ? "YES" : "NO";
        cout << ans << endl;
    }
}