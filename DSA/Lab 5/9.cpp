#include <bits/stdc++.h>
using namespace std;
#define outtext freopen("output.txt", "w", stdout)
#define _io                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#include <vector>
struct Order
{
    int t, l;
};
struct compare
{
    bool operator()(Order &a, Order &b)
    {
        return a.l > b.l;
    }
};
bool operator<(Order a, Order b)
{
    return a.t < b.t;
};

int minWaitingTime(int n, int arrvalTime[], int completeTime[])
{
    vector<Order> v;
    priority_queue<Order, vector<Order>, compare> pq;

    // collect data from two arrays.
    for (int i = 0; i < n; i++)
    {
        Order order;
        order.t = arrvalTime[i];
        order.l = completeTime[i];
        v.push_back(order);
    }
    sort(v.begin(), v.end());
    long long cur_t = 0;
    long long tot = 0;
    int idx = 0;
    while (true)
    {
        int i;
        for (i = idx; i < n; i++)
        {
            if (v[i].t <= cur_t)
                pq.push(v[i]);
            else
            {
                idx = i;
                break;
            }
        }

        if (i == n)
            idx = n;

        if (!pq.empty())
        {
            Order tmp = pq.top();
            tot += cur_t + tmp.l - tmp.t;
            cur_t += tmp.l;
            pq.pop();
        }

        else
        {
            if (idx != n)
                cur_t = v[idx].t;
        }

        if (idx == n && pq.empty())
            break;
    }
    return tot;
}

int main()
{
    outtext;
    _io;
    int n = 4;
    int arrvalTime[] = {0, 4, 2, 5};
    int completeTime[] = {4, 2, 3, 4};

    cout << minWaitingTime(n, arrvalTime, completeTime);
    return 0;
}