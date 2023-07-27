#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin >> n;
    vector<pair<int, int>> events;

    int x;
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> x;
        if (i % 2)
        {
            events.push_back(make_pair(x, -1));
        }
        else
        {
            events.push_back(make_pair(x, 1));
        }
    }
    sort(events.begin(), events.end());
    // for (auto x : events)
    // {
    //     cout << x.first << " " << x.second;
    //     cout << "\n";
    // }
    // create a vector of events pair<int, int> start, +1 end, -1
    int max = -1;
    int sum = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        sum += events[i].second;
        if (sum > max)
            max = sum;
    }
    cout << max << endl;
    return 0;
}