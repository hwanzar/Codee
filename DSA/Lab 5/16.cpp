#include <bits/stdc++.h>
using namespace std;
#define outtext freopen("output.txt", "w", stdout)
#define _io                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int leastAfter(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto x : nums)
    {
        pq.push(x);
    }
    for (int i = 0; i < k; i++)
    {
        int x = pq.top();
        pq.pop();
        x *= 2;
        pq.push(x);
    }
    return pq.top();
}

int main()
{
    outtext;
    _io;
    vector<int> nums{2, 3, 5, 7};
    int k = 3;
    cout << leastAfter(nums, k);

    return 0;
}